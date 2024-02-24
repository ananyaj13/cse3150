#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;

int main(){
    //student.cpp and student.h's main function
    Student student = get_student();

    int midterm = get_midterm(student);
    int final_exam = get_final_exam(student);
    vector<int> hw_grades = get_hw_grades(student);
    double total_grade = total_class_grade(midterm, final_exam, hw_grades);

    cout << "total grade : " << total_grade << endl;

    print_student(student);
    
    return 0;
}