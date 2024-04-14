#include <iostream>
#include "Point3d.h"

using namespace std;

std::ostream & operator<<(std::ostream &os, Point3d & p3d){
    
    os << "x = " << p3d.get_x() 
       << " y = " << p3d.get_y() 
       << " z = " << p3d.get_z();

    return os;
};

Point3d::Point3d() : x(0.0), y(0.0), z(0.0) {};
Point3d::Point3d(double all) : x(all), y(all), z(all) {};
Point3d::Point3d(const Point3d & p3d) : x(p3d.x), y(p3d.y), z(p3d.z) {};
Point3d::Point3d(double x, double y, double z) :  x(x), y(y), z(z) {};
Point3d::~Point3d() {};