#include <iostream>
#include "Point3d.h" 
#include "Triangle3d.h"

using namespace std;

int main() {

    Point3d p1(0.0, 0.0, 0.0);
    Point3d p2(1.0, 2.0, 0.0);
    Point3d p3(-1.0, 0.0, 0.0);

    Triangle3d triangle(p1,p2,p3);
    cout << triangle.pointDistance(p1,p2) << endl;
    cout << triangle.pointDistance(p1,p3) << endl;
    cout << triangle.pointDistance(p2,p3) << endl;
    cout << "That should have been the sqrt(5) = sqrt(1^2 + 2^2)" << endl;

    cout << triangle.computeArea() << endl;

    return 0;
}
