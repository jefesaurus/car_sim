#include "vis/glsl_points.h"
#include "base/logging.h"

const std::string vertex_shader = R"(
        #version 330
        uniform mat4 projection_matrix;
        layout(location = 0) in vec3 v_position;
        layout(location = 1) in vec4 v_color;
        layout(location = 2) in float v_size;
        out vec4 f_color;
        void main(void)
        {
        	f_color = v_color;
        	gl_Position = projection_matrix * vec4(v_position, 1.0f);
          gl_PointSize = v_size;
        }
        )";

const std::string fragment_shader = R"(
        #version 330
        in vec4 f_color;
        out vec4 color;
        void main(void)
        {
        	color = f_color;
        }
        )";

GlslPoints::GlslPoints() {
  CHECK(program_.AddShader(pangolin::GlSlFragmentShader, fragment_shader));
  CHECK(program_.AddShader(pangolin::GlSlVertexShader, vertex_shader));
  CHECK(program_.Link());

  // Generate
  glGenVertexArrays(1, &vertex_array_id_);
  glGenBuffers(1, &vertex_buffer_id_);

  glBindVertexArray(vertex_array_id_);
  glEnableVertexAttribArray(program_.GetAttributeHandle("v_position"));
  glEnableVertexAttribArray(program_.GetAttributeHandle("v_color"));
  glEnableVertexAttribArray(program_.GetAttributeHandle("v_size"));

  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id_);

  // Vertex buffer
  glVertexAttribPointer(program_.GetAttributeHandle("v_position"), 3, GL_FLOAT,
                        GL_FALSE, sizeof(Vertex),
                        reinterpret_cast<void*>(offsetof(Vertex, position)));

  // Color buffer
  glVertexAttribPointer(program_.GetAttributeHandle("v_color"), 4, GL_FLOAT,
                        GL_FALSE, sizeof(Vertex),
                        reinterpret_cast<void*>(offsetof(Vertex, color)));

  // Size buffer
  glVertexAttribPointer(program_.GetAttributeHandle("v_size"), 1,
                        GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        reinterpret_cast<void*>(offsetof(Vertex, size)));

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_.data(),
               GL_DYNAMIC_DRAW);


  // Cleanup
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  num_active_ = 0;
}

GlslPoints::~GlslPoints() {
  if (vertex_array_id_) {
    glDeleteVertexArrays(1, &vertex_array_id_);
    glDeleteBuffers(1, &vertex_buffer_id_);
    vertex_array_id_ = 0;
  }
}

void GlslPoints::AddVertex(const Vector3f& v, const Vector4f& c, float size) {
  if (num_active_ == BufferSize) Flush();
  vertices_[num_active_++] =
      Vertex{{v[0], v[1], v[2]}, {c[0], c[1], c[2], c[3]}, size};
}

void GlslPoints::SetProjectionModelViewMatrix(
    const pangolin::OpenGlMatrix& projection_model_view) {
  projection_model_view_ = projection_model_view;
}

void GlslPoints::Flush() {
  if (num_active_ == 0) return;
  program_.Bind();
  program_.SetUniform("projection_matrix", projection_model_view_);

  glBindVertexArray(vertex_array_id_);

  // Send data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id_);
  glBufferSubData(GL_ARRAY_BUFFER, 0, num_active_ * sizeof(Vertex), vertices_.data());

  // Draw
  glEnable(GL_PROGRAM_POINT_SIZE);
  glDrawArrays(GL_POINTS, 0, num_active_);
  glDisable(GL_PROGRAM_POINT_SIZE);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  program_.Unbind();

  num_active_ = 0;
}
