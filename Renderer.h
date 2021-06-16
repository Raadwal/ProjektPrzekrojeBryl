#pragma once
#include "Configurer.h"

#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

#include <memory>

class Renderer {
private:
  std::shared_ptr<Configurer> m_cfg;
  Matrix4 m_rotation_matrix;
  bool m_matrix_set;
  double m_plane_start_pos;
  bool m_saving;
  unsigned short int frame;

  Vector4 Scale(Vector4& original);
  Vector4 Rotate(Vector4& original, double x_angle, double y_angle, double z_angle);
  Vector4 ApplyPerspective(Vector4& original, double fov);
  Vector4 CenterScreen(Vector4& original);

  Vector4 TransformVector(Vector4& original, double fov = 45, double x_angle = 0, double y_angle = 0, double z_angle = 0);

  void DrawAxes(wxBufferedDC& dc, double fov = 45, double x_angle = 0, double y_angle = 0, double z_angle = 0);

  void DrawXPlane(wxBufferedDC& dc, double fov = 45, double x_angle = 0, double y_angle = 0, double z_angle = 0);
  void DrawYPlane(wxBufferedDC& dc, double fov = 45, double x_angle = 0, double y_angle = 0, double z_angle = 0);
  void DrawZPlane(wxBufferedDC& dc, double fov = 45, double x_angle = 0, double y_angle = 0, double z_angle = 0);

  void UpdatePlanePos(wxBufferedDC& dc, float speed);

  //Testowanie algorytmów do obcinania bry³
  void FindLinesX(wxBufferedDC& dc, std::vector<Segment>& data);
  void FindLinesY(wxBufferedDC& dc, std::vector<Segment>& data);
  void FindLinesZ(wxBufferedDC& dc, std::vector<Segment>& data);
  void Test(std::vector<Segment>& data); 
  void Test2(std::vector<Segment>& data, int axis_plane);
  void Test3(std::vector<Segment>& data);
  void Test4(std::vector<Segment>& data);
  void CogenSutherland(std::vector<Segment>& data);

public:
  Renderer(std::shared_ptr<Configurer> cfg) : m_cfg(cfg), m_rotation_matrix(Matrix4()), m_matrix_set(false), m_plane_start_pos(-2), m_saving(false), frame(0){}
  void Render(wxDC* parentDC, int width, int height);
};
