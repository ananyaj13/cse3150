#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point3d.h"
#include "Triangle3d.h"

TEST_CASE("Testing Point3d class") {
    SUBCASE("Testing default constructor") {
        Point3d p;
        CHECK(p.get_x() == 0.0);
        CHECK(p.get_y() == 0.0);
        CHECK(p.get_z() == 0.0);
    }

    SUBCASE("Testing constructor with all values") {
        Point3d p(2.0);
        CHECK(p.get_x() == 2.0);
        CHECK(p.get_y() == 2.0);
        CHECK(p.get_z() == 2.0);
    }

    SUBCASE("Testing constructor with specific values") {
        Point3d p(1.0, 2.0, 3.0);
        CHECK(p.get_x() == 1.0);
        CHECK(p.get_y() == 2.0);
        CHECK(p.get_z() == 3.0);
    }

    SUBCASE("Testing copy constructor") {
        Point3d p1(1.0, 2.0, 3.0);
        Point3d p2(p1);
        CHECK(p2.get_x() == 1.0);
        CHECK(p2.get_y() == 2.0);
        CHECK(p2.get_z() == 3.0);
    }

    SUBCASE("Testing setters") {
        Point3d p;
        p.set_x(5.0);
        p.set_y(6.0);
        p.set_z(7.0);
        CHECK(p.get_x() == 5.0);
        CHECK(p.get_y() == 6.0);
        CHECK(p.get_z() == 7.0);
    }

        SUBCASE("Testing constructor with negative values") {
        Point3d p(-1.0, -2.0, -3.0);
        CHECK(p.get_x() == -1.0);
        CHECK(p.get_y() == -2.0);
        CHECK(p.get_z() == -3.0);
    }

    SUBCASE("Testing copy constructor with zero values") {
        Point3d p1(0.0, 0.0, 0.0);
        Point3d p2(p1);
        CHECK(p2.get_x() == 0.0);
        CHECK(p2.get_y() == 0.0);
        CHECK(p2.get_z() == 0.0);
    }

    SUBCASE("Testing setters with mixed values") {
        Point3d p;
        p.set_x(-5.0);
        p.set_y(6.5);
        p.set_z(0.0);
        CHECK(p.get_x() == -5.0);
        CHECK(p.get_y() == 6.5);
        CHECK(p.get_z() == 0.0);
    }
}

TEST_CASE("Testing Triangle3d class") {
    SUBCASE("Testing default constructor") {
        Triangle3d t;
        CHECK(t.get_p1().get_x() == 0.0);
        CHECK(t.get_p2().get_x() == 0.0);
        CHECK(t.get_p3().get_x() == 0.0);
        CHECK(t.get_d12() == 0.0);
        CHECK(t.get_d13() == 0.0);
        CHECK(t.get_d23() == 0.0);
    }

    SUBCASE("Testing constructor with points") {
        Point3d p1(1.0, 2.0, 3.0);
        Point3d p2(4.0, 5.0, 6.0);
        Point3d p3(7.0, 8.0, 9.0);
        Triangle3d t(p1, p2, p3);
        CHECK(t.get_p1().get_x() == 1.0);
        CHECK(t.get_p2().get_x() == 4.0);
        CHECK(t.get_p3().get_x() == 7.0);
        CHECK(t.get_d12() == doctest::Approx(5.19615));
        CHECK(t.get_d13() == doctest::Approx(10.3923));
        CHECK(t.get_d23() == doctest::Approx(5.19615));
    }

    SUBCASE("Testing copy constructor") {
        Point3d p1(1.0, 2.0, 3.0);
        Point3d p2(4.0, 5.0, 6.0);
        Point3d p3(7.0, 8.0, 9.0);
        Triangle3d t1(p1, p2, p3);
        Triangle3d t2(t1);
        CHECK(t2.get_p1().get_x() == 1.0);
        CHECK(t2.get_p2().get_x() == 4.0);
        CHECK(t2.get_p3().get_x() == 7.0);
        CHECK(t2.get_d12() == doctest::Approx(5.19615));
        CHECK(t2.get_d13() == doctest::Approx(10.3923));
        CHECK(t2.get_d23() == doctest::Approx(5.19615));
    }

    SUBCASE("Testing computeArea") {
        Point3d p1(1.0, 1.0, 1.0);
        Point3d p2(1.0, 5.0, 1.0);
        Point3d p3(5.0, 1.0, 1.0);
        Triangle3d t(p1, p2, p3);
        CHECK(t.computeArea() == doctest::Approx(8.0));
    }

    SUBCASE("Testing constructor with points on different axes") {
        Point3d p1(1.0, 0.0, 0.0);
        Point3d p2(0.0, 5.0, 0.0);
        Point3d p3(0.0, 0.0, 10.0);
        Triangle3d t(p1, p2, p3);
        CHECK(t.get_p1().get_x() == 1.0);
        CHECK(t.get_p2().get_y() == 5.0);
        CHECK(t.get_p3().get_z() == 10.0);
        CHECK(t.get_d12() == doctest::Approx(5.0990));
        CHECK(t.get_d13() == doctest::Approx(10.0498));
        CHECK(t.get_d23() == doctest::Approx(11.1803));
    }

    SUBCASE("Testing computeArea with 0 and non-zero inputs") {
        Point3d p1(1.0, 1.0, 1.0);
        Point3d p2(2.0, 2.0, 2.0);
        Point3d p3(3.0, 3.0, 3.0);
        Triangle3d t(p1, p2, p3);
        CHECK(t.computeArea() == 0.0);
    }

    SUBCASE("Testing degenerate triangle with zero area") {
        Point3d p1(0.0, 0.0, 0.0);
        Point3d p2(1.0, 0.0, 0.0);
        Point3d p3(2.0, 0.0, 0.0);
        Triangle3d t(p1, p2, p3);
        CHECK(t.computeArea() == 0.0);
    }

}
