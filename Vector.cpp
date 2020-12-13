#include "Vector.hpp"
#include <iomanip>

using namespace std;

vector<double> operator+(const vector<double> &a, const vector<double> &b)
{
  vector<double> result;

  int len = a.size() < b.size() ? a.size() : b.size();

  for (int i = 0; i < len; ++i)
  {
    result.push_back(a[i] + b[i]);
  }

  return result;
}

vector<double> operator+(const vector<double> &v, const double &k)
{
  vector<double> result;

  for (double num : v)
  {
    result.push_back(num + k);
  }

  return result;
}

vector<double> operator/(const vector<double> &v, const double &k)
{
  vector<double> result;

  for (double num : v)
  {
    result.push_back(num / k);
  }

  return result;
}

vector<double> operator*(const vector<double> &v, const double &k)
{
  vector<double> result;

  for (double num : v)
  {
    result.push_back(num * k);
  }

  return result;
}

ostream &operator<<(ostream &out, const vector<double> &v)
{
  for (size_t i = 0; i < v.size(); i++)
  {
    out << v[i] << endl;
  }
  return out;
}

ostream &operator<<(ostream &out, const vector<Particle> &v)
{
  for (const Particle &p : v)
  {
    out << setprecision(5);
    out << setw(8) << p << ' ';
  }
  return out;
}