#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

using namespace std;

TEST_CASE("createStudent function") {
    SUBCASE("Creating a student with valid data") {
        Student student = createStudent(1, "Alice", 90, 85, {80, 85, 90});
        CHECK(student.id == 1);
        CHECK(student.name == "Alice");
        CHECK(student.midterm == 90);
        CHECK(student.final_exam == 85);
        CHECK(student.hw_grades == vector<int>{80, 85, 90});
    }
    SUBCASE("EDGE CASE") {
        CHECK_THROWS_AS(createStudent(1, "", 90, 85, {80, 85, 90}), invalid_argument);
    }

    SUBCASE("EDGE CASE") {
        CHECK_THROWS_AS(createStudent(1, "Alice", 90, 85, {}), invalid_argument);
    }

}

TEST_CASE("total_class_grade function") {
    SUBCASE("1") {
        double grade = total_class_grade(90, 85, {80, 85, 90});
        CHECK(grade == 86.5);
    }

    SUBCASE("2 --> EDGE CASE") {
        CHECK_THROWS_AS(total_class_grade(0, 0, {}), invalid_argument);
    }

    SUBCASE("3") {
        double grade = total_class_grade(90, 1, {8, 60, 100});
        CHECK(grade == 49.7);
    }
}

TEST_CASE("get_id function") {
    SUBCASE("Getting ID of a student") {
        Student student;
        student.id = 2;
        CHECK(get_id(student) == 2);
    }
}

TEST_CASE("EDGE CASE") { //values are initialized to 0
    Student student2;
    CHECK(get_id(student2) == 0);
}


TEST_CASE("get_name function") {
    SUBCASE("Getting name of a student") {
        Student student;
        student.name = "Bob";
        CHECK(get_name(student) == "Bob");
    }

    SUBCASE("EDGE CASE") {
        Student student;
        CHECK_THROWS_AS(get_name(student), invalid_argument);
    }
}

TEST_CASE("get_midterm function") {
    SUBCASE("Getting midterm of a student") {
        Student student;
        student.midterm = 90;
        CHECK(get_midterm(student) == 90);
    }
}

TEST_CASE("get_final_exam function") {
    SUBCASE("Getting final exam score of a student") {
        Student student;
        student.final_exam = 85;
        CHECK(get_final_exam(student) == 85);
    }
}

TEST_CASE("get_hw_grades function") {
    SUBCASE("Getting homework grades of a student") {
        Student student;
        student.hw_grades = {80, 85, 90};
        CHECK(get_hw_grades(student) == vector<int>{80, 85, 90});
    }
}

TEST_CASE("All-Functions-Togehter Check"){
    Student student = createStudent(9999, "Terngeoru Hfowurhf Hioeif", 0, 5, {100, 105, 100, 0, 9});
    
    //check details
    CHECK(student.id == get_id(student));
    CHECK(student.name == get_name(student));
    CHECK(student.midterm == get_midterm(student));
    CHECK(student.final_exam == get_final_exam(student));
    CHECK(student.hw_grades == get_hw_grades(student));

    //check grade
    double grade = total_class_grade(get_midterm(student), get_final_exam(student), get_hw_grades(student));
    CHECK(grade == 26.62);
}