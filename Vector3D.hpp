#if !defined(VECTOR3D)
#define VECTOR3D

#include <iostream>

using namespace std;

class Vector3D
{
  double arr[3];

public:
  Vector3D();                             // default constructor
  Vector3D(double x, double y, double z); // constructor
  Vector3D(const Vector3D &other);        // copy constructor
  ~Vector3D() {}

  double getX() const;
  double getY() const;
  double getZ() const;

  void setX(double x);
  void setY(double y);
  void setZ(double z);

  Vector3D &operator=(const Vector3D &vector3d);
  friend istream &operator>>(istream &in, Vector3D &vector);
  friend ostream &operator<<(ostream &out, const Vector3D &vector);
  friend Vector3D operator+(const Vector3D &a, const Vector3D &b); // {ax, ay, az}+{bx, by, bz} = {ax+bx, ay+by, az+bz}
  friend Vector3D operator*(const Vector3D &a, const double &k);   // multiply every entry of a with k
  friend Vector3D operator/(const Vector3D &a, const double &k);   // divide every entry of a with k
};

istream &operator>>(istream &in, Vector3D &vector);
ostream &operator<<(ostream &out, const Vector3D &vector);
Vector3D operator+(const Vector3D &a, const Vector3D &b);
Vector3D operator*(const Vector3D &vector, const double &k);
Vector3D operator/(const Vector3D &vector, const double &k);

#endif // VECTOR3D
