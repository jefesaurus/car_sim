#include <pangolin/pangolin.h>
#include <pangolin/gl/glsl.h>

#include "math/eigen_types.h"

// Ring buffer to add dynamic vertices to scene.
class GlslPoints {
 public:
  static constexpr int BufferSize = 512;
  GlslPoints();
  ~GlslPoints();

  void AddVertex(const Vector3f& v, const Vector4f& c, float size);

  void SetProjectionModelViewMatrix(
      const pangolin::OpenGlMatrix& projection_model_view);

  // Draw points.
  void Flush();

 private:
  struct Vertex {
    std::array<float, 3> position;
    std::array<float, 4> color;
    float size;
  };

  // Shader program
  pangolin::GlSlProgram program_;

  // Vertex attibutes
  int num_active_;
  std::array<Vertex, BufferSize> vertices_;

  // Vertex array object id
  GLuint vertex_array_id_;

  // IDs for the vertex, color, and size buffers
  GLuint vertex_buffer_id_;

  // Projection matrix
  pangolin::OpenGlMatrix projection_model_view_;
};
