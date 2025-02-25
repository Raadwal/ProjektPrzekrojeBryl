#include "HelperStructs.h"

Matrix4 Matrix4::operator* (const Matrix4& rhs)
{
  int i, j, k;
  Matrix4 tmp;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    {
      tmp.data[i][j] = 0.0;
      for (k = 0; k < 4; k++)
        tmp.data[i][j] = tmp.data[i][j] + (data[i][k] * rhs.data[k][j]);
    }
  return tmp;
}

Vector4 operator* (const Vector4& gVector, const Matrix4& gMatrix)
{
  unsigned int i, j;
  Vector4 tmp;

  for (i = 0; i < 4; i++)
  {
    tmp.data[i] = 0.0;
    for (j = 0; j < 4; j++) tmp.data[i] = tmp.data[i] + (gMatrix.data[i][j] * gVector.data[j]);
  }
  return tmp;
}

Vector4 Matrix4::operator* (const Vector4& gVector)
{
  unsigned int i, j;
  Vector4 tmp;

  for (i = 0; i < 4; i++)
  {
    tmp.data[i] = 0.0;
    for (j = 0; j < 4; j++) tmp.data[i] = tmp.data[i] + (data[i][j] * gVector.data[j]);
  }
  return tmp;
}