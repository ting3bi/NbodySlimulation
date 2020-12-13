#include "Vector3D.hpp"
#include <iomanip>

using namespace std;

Vector3D::Vector3D() {}

Vector3D::Vector3D(double x, double y, double z)
{
    arr[0] = x;
    arr[1] = y;
    arr[2] = z;
}

Vector3D::Vector3D(const Vector3D &other)
{
    setX(other.getX());
    setY(other.getY());
    setZ(other.getZ());
}

double Vector3D::getX() const
{
    return arr[0];
}

double Vector3D::getY() const
{
    return arr[1];
}

double Vector3D::getZ() const
{
    return arr[2];
}

void Vector3D::setX(double x)
{
    arr[0] = x;
}

void Vector3D::setY(double y)
{
    arr[1] = y;
}

void Vector3D::setZ(double z)
{
    arr[2] = z;
}

Vector3D &Vector3D::operator=(const Vector3D &v)
{
    setX(v.getX());
    setY(v.getY());
    setZ(v.getZ());

    return *this;
}

istream &operator>>(istream &in, Vector3D &vector)
{
    in >> vector.arr[0] >> vector.arr[1] >> vector.arr[2];
    return in;
}

ostream &operator<<(ostream &out, const Vector3D &vector)
{
    out.precision(6);
    out << setw(15) << vector.getX() << ' ' << setw(15) << vector.getY() << ' ' << setw(15) << vector.getZ() << ' ';
    return out;
}

Vector3D operator+(const Vector3D &a, const Vector3D &b)
{
    double x = a.getX() + b.getX();
    double y = a.getY() + b.getY();
    double z = a.getZ() + b.getZ();

    Vector3D result(x, y, z);

    return result;
}

Vector3D operator*(const Vector3D &vector, const double &k)
{
    double x = vector.getX() * k;
    double y = vector.getY() * k;
    double z = vector.getZ() * k;

    Vector3D result(x, y, z);

    return result;
}

Vector3D operator/(const Vector3D &vector, const double &k)
{
    double x = vector.getX() / k;
    double y = vector.getY() / k;
    double z = vector.getZ() / k;

    Vector3D result(x, y, z);

    return result;
}
