#include <iostream>
#include <fstream>
#include "student.h"
#include <cmath>
#include <iomanip>

using namespace std;


// Student::Student() {};
// Student::Student(int id, string name, int midterm, int final_exam, vector<int> & hw_grades):
//                  id(id), name(name), midterm(midterm), final_exam(final_exam), hw_grades(hw_grades) {};


//creating a student
Student createStudent(const int id, const string name, const int midterm, const int final_exam, const vector<int> &hw_grades){
    Student student;
    if (id <= 0) {
        throw invalid_argument("ID must be a positive integer");
    }
    student.id = id;

    if (name.empty()) {
        throw invalid_argument("Name cannot be empty");
    }
    student.name = name;

    if (midterm < 0 || midterm > 100) {
        throw invalid_argument("Midterm grade must be between 0 and 100");
    }
    student.midterm = midterm;

    if (final_exam < 0 || final_exam > 100) {
        throw invalid_argument("Final exam grade must be between 0 and 100");
    }
    student.final_exam = final_exam;

    if (hw_grades.empty()) {
        throw invalid_argument("At least one homework grade must be provided");
    }
    student.hw_grades = hw_grades;
    
    return student;
}

//computing student's class grade
double total_class_grade(int midterm, int final_exam, vector<int> hw_grades){

    if (hw_grades.size() == 0){
        throw invalid_argument("At least one homework grade must be provided");
    }
    //30% of midterm:
    double midterm_half = (double)midterm * 0.3;
    // cout << (double)midterm << " " << midterm_half << endl;

    //30% of final
    double final_half = (double)final_exam * 0.3;
    // cout << (double)final_exam << " " << final_half << endl;

    //40% of homework
    int sum = 0;
    for(int element : hw_grades){
        sum += element;
    }
    // cout << sum << endl;
    double average_hw = (double)sum / hw_grades.size();
    // cout << hw_grades.size() << endl;
    // cout << average_hw << endl;
    double homework_half = average_hw * 0.4;
    // cout << homework_half << endl;

    //total grade calculation
    double total = homework_half + midterm_half + final_half;
    total = round(total * 100) / 100;

    return total;
}


//get functions
Student get_student() { //get student function for using the main function in main_student()
    Student student;
    cout << "Enter an ID value" << endl;
    cin >> student.id;

    cout << "Enter a name" << endl;
    cin >> student.name;

    int midterm;
    cout << "Enter a Midterm value" << endl;
    cin >> midterm;
    student.midterm = (int)midterm;

    int final_exam;
    cout << "Enter a Final Exam Value" << endl;
    cin >> final_exam;
    student.final_exam = (int)final_exam;

    vector<int> hw_grades = {};
    int value = 0;
    while(value != -1){
        cout << "Enter a hw grade...Once your're done, enter -1" << endl;
        cin >> value;
        if (value > -1){
            hw_grades.push_back((int)value);
        }
    }
    student.hw_grades = hw_grades;
    return student;
}

int get_id(Student student){
    if (student.id >= 0)
        return student.id;
    else{
        return -1;
    }
}


string get_name(Student student){
    if (student.name.empty()){
        throw invalid_argument("Name cannot be empty");;
    }
    return student.name;
}


int get_midterm(Student student){
    if (student.midterm >= 0)
        return student.midterm;
    else{
        return -1;
    }
}


int get_final_exam(Student student){
    
    if (student.final_exam >= 0)
        return student.final_exam;
    else{
        return -1;
    }
}


vector<int> get_hw_grades(Student student){
    if (student.hw_grades.size() >= 0){
        return student.hw_grades;
    }
    else{
        throw invalid_argument("At least one homework grade must be provided");
    }
}

void print_student(Student student){
    cout << student.id << endl;
    cout<< student.name << endl;
    cout << student.midterm << endl;
    cout << student.final_exam << endl;
    cout << "elements in the vector: " << endl;
    for (int element : student.hw_grades){
        
        cout << element << " | ";
    }
    cout << endl;
}