#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int final_exam;
    int midterm;
    vector<int> hw_grades;
};

//methods to create student
Student createStudent(const int id, const string name, const int midterm, const int final_exam, const vector<int> &hw_grades);
Student get_student();

//computing total class grade
double total_class_grade(int midterm, int final_exam, vector<int> hw_grades);

//functions to get values
int get_id(Student student);
string get_name(Student student);
int get_midterm(Student student);
int get_final_exam(Student student);
vector<int> get_hw_grades(Student student);

//printing student
void print_student(Student student);

#endif