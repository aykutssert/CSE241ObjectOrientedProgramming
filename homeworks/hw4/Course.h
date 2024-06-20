#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"

using namespace std;



namespace PA4{
    class Student;
class Course
{

private:
    string name;      // course name
    string code;      // course code
    int student_size; // how many students take this course?

public:
    int getCourseStudentSize() const;  // getter for student_size
    void DecreaseStudentSize();        // student_size--
    void IncreaseStudentSize();        // student_size++
    void SetCourseStudentSize(int);    // setter for student_size
    Course();                          // default constructor
    Course(string, string);            // set constructor
    string getName() const;            // getter for name
    string getCode() const;            // getter for code
    void setName(string);              // setter for name
    void setCode(string);              // setter for code
    Course(const Course &);            // copy constructor
    Course &operator=(const Course &); // assign operator
    ~Course();                         // destructor
    PA4::Student *student;                  // array of students taking this course
};

}
#endif