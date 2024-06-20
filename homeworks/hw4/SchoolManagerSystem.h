#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H
using namespace std;
#include <string>
#include "Student.h"
#include "Course.h"

class SchoolManagerSystem
{

private:
    int All_student_size; // total number of students
    int All_course_size;  // total number of courses

public:
    int getAllStudentSize() const; // getter for total number of students
    int getAllCourseSize() const;  // getter for total number of courses

    void addStudent(); // add student

    void addCourse(); // add course

    void selectStudent();
    void selectCourse();

    SchoolManagerSystem();  // default constructor
    ~SchoolManagerSystem(); // destructor

    void StudentMenu(); // Student Menu
    void CourseMenu();  // Course Menu
    void MainMenu();    // Main Menu
    PA4::Course *course;     // dynamic array with all students
    PA4::Student *student;   // dynamic array with all courses
};

#endif