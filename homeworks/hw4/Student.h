#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Course.h"

using namespace std;



namespace PA4{
  class Course;
class Student
{

private:
  string name;     // student name
  int id;          // student id
  int course_size; // How many courses does the student have?

public:
  Student();            // default constructor
  Student(string, int); // set constructor
  ~Student();           // destructor

  void setName(string); // setter for name
  void setId(int);      // setter for id

  Student(const Student &);            // copy constructor
  Student &operator=(const Student &); // assign operator
  string getName() const;              // getter for name
  int getId() const;                   // getter for id
  int getStudentCourseSize() const;    // getter for course_size
  void DecreaseCourseSize();           // course_size--
  void IncreaseCourseSize();           // course_size++
  void SetStudentCourseSize(int);      // setter for course_size
  Course *course;                      // array of courses the student has
};

}
#endif