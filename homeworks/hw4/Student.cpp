#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

namespace PA4{
Student::Student()
{
    name = "";
    id = 0;
    course = nullptr;
    course_size = 0;
}

Student::Student(string _name, int _id)
{

    this->name = _name;
    this->id = _id;
    course = nullptr;
    course_size = 0;
}

string Student::getName() const
{
    return name;
}

int Student::getId() const
{
    return id;
}

Student::~Student()
{
    delete[] course;
}

int Student::getStudentCourseSize() const
{
    return course_size;
}

void Student::DecreaseCourseSize()
{
    course_size--;
}

void Student::IncreaseCourseSize()
{
    course_size++;
}

void Student::SetStudentCourseSize(int _number)
{
    course_size = _number;
}

void Student::setName(string _name)
{
    name = _name;
}

void Student::setId(int _id)
{
    id = _id;
}

Student::Student(const Student &copy)
{
    if (this != &copy)
    {
        name = copy.getName();
        id = copy.getId();
        course_size = copy.getStudentCourseSize();
        delete[] course;
        course = new PA4::Course[course_size];

        for (int i = 0; i < course_size; i++)
        {
            course[i].setName(copy.course[i].getName());
            course[i].setCode(copy.course[i].getCode());
        }
    }
}


Student &Student::operator=(const Student &copy)
{

    if (this != &copy)
    {
        name = copy.getName();
        id = copy.getId();
        course_size = copy.getStudentCourseSize();
        delete[] course;
        course = new Course[course_size];

        for (int i = 0; i < course_size; i++)
        {

            course[i].setName(copy.course[i].getName());
            course[i].setCode(copy.course[i].getCode());
        }
    }
    return *this;
}

}