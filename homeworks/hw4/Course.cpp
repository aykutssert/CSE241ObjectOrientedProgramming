#include <iostream>
#include <string>
#include "Course.h"

using namespace std;


namespace PA4{
Course::Course()
{
    name = "";
    code = "";
    student = nullptr;
    student_size = 0;
}

Course::Course(string _name, string _code)
{

    this->name = _name;
    this->code = _code;
    student = nullptr;
    student_size = 0;
}
string Course::getName() const
{
    return name;
}
string Course::getCode() const
{
    return code;
}
void Course::setName(string _name)
{

    name = _name;
}
void Course::setCode(string _code)
{
    code = _code;
}
Course::~Course()
{
    delete[] student;
}

int Course::getCourseStudentSize() const
{
    return student_size;
}
void Course::SetCourseStudentSize(int _number)
{
    student_size = _number;
}
void Course::DecreaseStudentSize()
{
    student_size--;
}
void Course::IncreaseStudentSize()
{
    student_size++;
}
Course::Course(const Course &copy)
{
    if (this != &copy)
    {
        name = copy.getName();
        code = copy.getCode();
        student_size = copy.getCourseStudentSize();
        delete[] student;
        student = new PA4::Student[student_size];

        for (int i = 0; i < student_size; i++)
        {
            student[i].setName(copy.student[i].getName());
            student[i].setId(copy.student[i].getId());
        }
    }
}
Course &Course::operator=(const Course &copy)
{
    if (this != &copy)
    {
        name = copy.getName();
        code = copy.getCode();
        student_size = copy.getCourseStudentSize();
        delete[] student;
        student = new PA4::Student[student_size];

        for (int i = 0; i < student_size; i++)
        {
            student[i].setName(copy.student[i].getName());
            student[i].setId(copy.student[i].getId());
        }
    }
    return *this;
}
}