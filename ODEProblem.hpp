#ifndef ODEPROBLEM_H
#define ODEPROBLEM_H

#include <vector>

using namespace std;

class ODEProblem
{
public:
    virtual vector<double> fcn(const vector<double> &vec) = 0;
    virtual vector<double> getY() = 0;
    virtual void setY(vector<double> &y) = 0;
    virtual ~ODEProblem() {}
};

#endif // ODEPROBLEM_H
