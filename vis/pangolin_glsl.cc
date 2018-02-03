#include "base/init.h"
#include "vis/glsl_points.h"

void DrawPoints() {
  pangolin::CreateWindowAndBind("Main", 640, 480);

  auto cam = pangolin::OpenGlRenderState(
      pangolin::ProjectionMatrix(640, 480, 420, 420, 320, 240, 0.1, 1000),
      pangolin::ModelViewLookAt(-1, 1, -1, 0, 0, 0, pangolin::AxisY));

  pangolin::Display("cam")
      .SetBounds(0, 1.0f, 0, 1.0f, -640 / 480.0)
      .SetHandler(new pangolin::Handler3D(cam));

  GlslPoints points;
  while (!pangolin::ShouldQuit()) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    points.AddVertex(Vector3f(0.0, 0.0, 0.0), Vector4f(1, 0, 0, 1), 10.0);
    points.AddVertex(Vector3f(1.0, 1.0, 1.0), Vector4f(0, 1, 0, 1), 15.0);
    points.AddVertex(Vector3f(0.5, 0.5, -1.0), Vector4f(0, 0, 1, 1), 30.0);
    points.SetProjectionModelViewMatrix(cam.GetProjectionModelViewMatrix());
    points.Flush();
    pangolin::FinishFrame();
  }
}

int main(int argc, char** argv) {
  Init(&argc, &argv);
  DrawPoints();
  return 0;
}
