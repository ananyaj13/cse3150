#ifndef _TRIANGLE_3D_H_
#define _TRIANGLE_3D_H_

#include <iostream>

#include "Point3d.h"

using namespace std;

struct Triangle3d {

    Triangle3d();
    Triangle3d(const Triangle3d & p3d);
    Triangle3d(Point3d p1,Point3d p2, Point3d p3);
    ~Triangle3d();

    private:
        Point3d p1;
        Point3d p2;
        Point3d p3;

        double d12;
        double d13; 
        double d23;

    public:
        Point3d & get_p1() { return p1; }
        Point3d & get_p2() { return p2; }
        Point3d & get_p3() { return p3; }

        double pointDistance(const Point3d left, const Point3d right);

        double get_d12() const { return d12; }
        double get_d13() const { return d13; }
        double get_d23() const { return d23; }

        double computeArea();

};


#endif
   