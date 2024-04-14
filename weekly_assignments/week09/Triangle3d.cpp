#include <iostream>
#include <cmath>

#include "Point3d.h"
#include "Triangle3d.h"

using namespace std;


std::ostream & operator<<(std::ostream &os, Triangle3d & p3d)
{
    os << "x = " << p3d.get_p1().get_x()
       << " y = " << p3d.get_p2().get_x()
       << " z = " << p3d.get_p3().get_x();

    return os;
};

Triangle3d::Triangle3d() : p1{0.0}, p2{0.0}, p3{0.0}, d12{0.0}, d13{0.0}, d23{0.0} {
    d12 = pointDistance(p1, p2);
    d13 = pointDistance(p1, p3);
    d23 = pointDistance(p2, p3);
};
Triangle3d::Triangle3d(const Triangle3d & p3d) : p1(p3d.p1),p2(p3d.p2), p3(p3d.p3), d12(p3d.d12), d13(p3d.d13), d23(p3d.d23){};
Triangle3d::Triangle3d(Point3d p1,Point3d p2, Point3d p3) :  p1{p1}, p2{p2}, p3{p3} {
    d12 = pointDistance(p1, p2);
    d13 = pointDistance(p1, p3);
    d23 = pointDistance(p2, p3);
};
Triangle3d::~Triangle3d() {};

double square(double value) { return value * value; }

double Triangle3d::pointDistance(Point3d left, Point3d right) {
    double radicand = square(left.get_x() - right.get_x()) + square(left.get_y() - right.get_y()) + square(left.get_z() - right.get_z());

    return sqrt(radicand);
}

double Triangle3d::computeArea() {
    // cout << "d12: " << d12 << "       d13: " << d13 << "         d23: " << d23 << endl;
    double s = (d12 + d13 + d23) / 2.0;
    return sqrt(s * (s - d12) * (s - d13) * (s - d23));
}
   