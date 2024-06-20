
#include <iostream>
#include "SchoolManagerSystem.h"
#include "Student.h"
#include "Course.h"

#include <string>

using namespace std;


SchoolManagerSystem::SchoolManagerSystem()
{
    int choice;
    course = nullptr;
    student = nullptr;
    All_student_size = 0;
    All_course_size = 0;

    do
    {

        MainMenu();
        cin >> choice;

        if (choice == 0)
            exit(0);

        if (choice == 1)
        {
            int choice;
            do
            {
                StudentMenu();
                cin >> choice;

                if (choice == 0)
                {

                    break;
                }

                if (choice == 1)
                {
                    addStudent();
                }
                if (choice == 2)
                {
                    selectStudent();
                }
            } while (1);
        }

        if (choice == 2)
        {
            int choice;
            do
            {
                CourseMenu();

                cin >> choice;

                if (choice == 0)
                {
                    break;
                }

                if (choice == 1)
                {
                    addCourse();
                }
                if (choice == 2)
                {

                    selectCourse();
                }
            } while (1);
        }

        if (choice == 3)
        {
            for (int i = 0; i < All_student_size; ++i)
            {
                cout << student[i].getName() << " " << student[i].getId() << endl;
            }
        }

        if (choice == 4)
        {
            for (int i = 0; i < All_course_size; ++i)
            {
                cout << course[i].getCode() << " " << course[i].getName() << endl;
            }
        }

    } while (1);
}

SchoolManagerSystem::~SchoolManagerSystem()
{
    delete[] course;
    delete[] student;
}

void SchoolManagerSystem::MainMenu()
{

    cout << "0 exit\n";
    cout << "1 student\n";
    cout << "2 course\n";
    cout << "3 list_all_students\n";
    cout << "4 list_all_courses\n";
}

void SchoolManagerSystem::StudentMenu()
{
    cout << "0 up\n";
    cout << "1 add_student\n";
    cout << "2 select_student\n";
}
void SchoolManagerSystem::CourseMenu()
{
    cout << "0 up\n";
    cout << "1 add_course\n";
    cout << "2 select_course\n";
}

void SchoolManagerSystem::addStudent()
{
    int id;
    string input, name;
    int flag = 1;
    cin.ignore();
    getline(cin, input);
    id = stoi(input.substr(input.find_last_of(' ') + 1));
    name = input.substr(0, input.find_last_of(' '));

    for (int i = 0; i < All_student_size; ++i)
    {
        if (student[i].getName() == name && student[i].getId() == id)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        
        PA4::Student obj_student(name, id);
        if (student == nullptr)
        {
           
            student = new PA4::Student[1];
            student[0] = obj_student;
            All_student_size++;
        }
        else
        {
            PA4::Student *temp = new PA4::Student[All_student_size + 1];
            for (int i = 0; i < All_student_size; i++)
            {
                temp[i] = student[i];
            }
            temp[All_student_size] = obj_student;
            All_student_size++;

            delete[] student;
            student = new PA4::Student[All_student_size];
            for (int i = 0; i < All_student_size; i++)
            {
                student[i] = temp[i];
            }

            delete[] temp;
        }
    }
}
void SchoolManagerSystem::selectStudent()
{
    int choice;
    int id;
    string input, name;

    cin.ignore();
    getline(cin, input);
    id = stoi(input.substr(input.find_last_of(' ') + 1));
    name = input.substr(0, input.find_last_of(' '));

    int index = -1;
    for (int i = 0; i < All_student_size; ++i)
    {
        if (name == student[i].getName() && id == student[i].getId())
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        do
        {
            cout << "0 up\n";
            cout << "1 delete_student\n";
            cout << "3 add_selected_student_to_a_course\n";
            cout << "4 drop_selected_student_from_a_course\n";

            cin >> choice;
            if (choice == 0)
            {
                break;
            }
            if (choice == 1)
            {
                
                PA4::Student *temp = new PA4::Student[All_student_size];
                for (int i = 0; i < index; i++)
                {
                    temp[i] = student[i];
                }
                for (int i = index + 1; i < All_student_size; i++)
                {
                    temp[index++] = student[i];
                }
                All_student_size--;
                delete[] student;
                student = new PA4::Student[All_student_size];
                for (int i = 0; i < All_student_size; i++)
                {
                    student[i] = temp[i];
                }
                int whichCourse;
                int whichStudent;

                for (int i = 0; i < All_course_size; i++)
                {
                    
                    for (int j = 0; j < course[i].getCourseStudentSize(); j++)
                    {
                        if (course[i].student[j].getName() == name && course[i].student[j].getId() == id)
                        {   
                           
                            whichCourse = i;
                            whichStudent = j;
                            int temp_whichStudent=whichStudent;

                            PA4::Student *temp = new PA4::Student[course[whichCourse].getCourseStudentSize()];
                            for (int k = 0; k < whichStudent; k++)
                            {   
                                
                                temp[k] = course[whichCourse].student[k];
                            }

                            for (int m = whichStudent + 1; m < course[whichCourse].getCourseStudentSize(); m++)
                            {   
                                
                                temp[temp_whichStudent++] = course[i].student[m];
                            }
                            
                            course[whichCourse].DecreaseStudentSize();
                            
                            delete[] course[whichCourse].student;
                            course[whichCourse].student = new PA4::Student[course[whichCourse].getCourseStudentSize()];
                            for (int j = 0; j < course[whichCourse].getCourseStudentSize(); j++)
                            {   
                               
                                course[whichCourse].student[j] = temp[j];
                            }

                        }
                    }
                }
                
                break;
            }
            if (choice == 3)
            {
                do
                {

                    int flag = 0, flag2 = 0;
                    cout << "0 up\n";
                    for (int i = 0; i < All_course_size; ++i)
                    {
                        flag = 0;
                        for (int j = 0; j < student[index].getStudentCourseSize(); j++)
                        {
                            if (course[i].getName() == student[index].course[j].getName() && course[i].getCode() == student[index].course[j].getCode())
                                flag = 1;
                        }

                        if (flag == 0)
                        {
                            cout << i + 1 << " " << course[i].getCode() << " " << course[i].getName() << endl;
                            flag2 = 1;
                        }
                    }
                    int input;

                    cin >> input;

                    if (input == 0)
                    {
                        break;
                    }
                    if (flag2 == 1)
                    {

                        input = input - 1;

                        if (student[index].course == nullptr)
                        {

                            student[index].SetStudentCourseSize(1);
                            student[index].course = new PA4::Course[1];
                            student[index].course[0].setName(course[input].getName());
                            student[index].course[0].setCode(course[input].getCode());
                        }
                        else
                        {
                            PA4::Course *temp = new PA4::Course[student[index].getStudentCourseSize() + 1];
                            for (int i = 0; i < student[index].getStudentCourseSize(); i++)
                            {
                                temp[i] = student[index].course[i];
                            }

                            temp[student[index].getStudentCourseSize()].setName(course[input].getName());
                            temp[student[index].getStudentCourseSize()].setCode(course[input].getCode());
                            student[index].IncreaseCourseSize();

                            delete[] student[index].course;
                            student[index].course = new PA4::Course[student[index].getStudentCourseSize()];
                            for (int i = 0; i < student[index].getStudentCourseSize(); i++)
                            {
                                student[index].course[i] = temp[i];
                            }

                            delete[] temp;
                        }

                        if (course[input].student == nullptr)
                        {

                            course[input].SetCourseStudentSize(1);

                            course[input].student = new PA4::Student[1];

                            course[input].student[0].setName(name);

                            course[input].student[0].setId(id);
                        }
                        else
                        {

                            PA4::Student *temp = new PA4::Student[course[input].getCourseStudentSize() + 1];
                            for (int i = 0; i < course[input].getCourseStudentSize(); i++)
                            {
                                temp[i] = course[input].student[i];
                            }

                            temp[course[input].getCourseStudentSize()].setName(name);
                            temp[course[input].getCourseStudentSize()].setId(id);
                            course[input].IncreaseStudentSize();

                            delete[] course[input].student;
                            course[input].student = new PA4::Student[course[input].getCourseStudentSize()];
                            for (int i = 0; i < course[input].getCourseStudentSize(); i++)
                            {
                                course[input].student[i] = temp[i];
                            }

                            delete[] temp;
                        }
                        break;
                    }

                } while (1);
            }
            if (choice == 4)
            {
                do
                {
                    int flag = 0, flag2 = 0;
                    cout << "0 up\n";
                    for (int i = 0; i < All_course_size; ++i)
                    {
                        for (int j = 0; j < student[index].getStudentCourseSize(); j++)
                        {
                            if (course[i].getName() == student[index].course[j].getName() && course[i].getCode() == student[index].course[j].getCode())
                            {
                                cout << i + 1 << " " << course[i].getCode() << " " << course[i].getName() << endl;
                                flag2 = 1;
                            }
                        }
                    }
                    int input;

                    cin >> input;

                    if (input == 0)
                        break;
                    if (flag2 == 1)
                    {
                        input = input - 1;
                        int temp_input = input;

                        PA4::Course *temp = new PA4::Course[student[index].getStudentCourseSize()];
                        for (int i = 0; i < input; i++)
                        {
                            temp[i] = student[index].course[i];
                        }
                        for (int i = input + 1; i < student[index].getStudentCourseSize(); i++)
                        {
                            temp[temp_input++] = student[index].course[i];
                        }
                        student[index].DecreaseCourseSize();
                        delete[] student[index].course;
                        student[index].course = new PA4::Course[student[index].getStudentCourseSize()];
                        for (int i = 0; i < student[index].getStudentCourseSize(); i++)
                        {
                            student[index].course[i] = temp[i];
                        }

                        
                            for (int j = 0; j < course[input].getCourseStudentSize(); j++)
                            {

                                if (course[input].student[j].getName()== name && course[input].student[j].getId() == id)
                                {

                                    PA4::Student *temp = new PA4::Student[course[input].getCourseStudentSize()];
                                    for (int k = 0; k < j; k++)
                                    {
                                        temp[k] = course[input].student[k];
                                    }
                                    for (int m = j + 1; m < course[input].getCourseStudentSize(); m++)
                                    {
                                        temp[j++] = course[input].student[m];
                                    }
                                    course[input].DecreaseStudentSize();
                                    delete[] course[input].student;
                                    course[input].student = new PA4::Student[course[input].getCourseStudentSize()];
                                    for (int n = 0; n < course[input].getCourseStudentSize(); n++)
                                    {
                                        course[input].student[n] = temp[n];
                                    }
                                }
                            }
                        
                        break;
                    }
                } while (1);
            }

        } while (1);
    }
}
void SchoolManagerSystem::addCourse()
{
    string input, name, code;
    int flag = 1;

    cin.ignore();
    getline(cin, input);
    code = input.substr(0, input.find_first_of(' '));
    name = input.substr(input.find_first_of(' ') + 1);

    for (int i = 0; i < All_course_size; ++i)
    {
        if (course[i].getName() == name && course[i].getCode() == code)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        PA4::Course c1(name, code);
        if (course == nullptr)
        {

            course = new PA4::Course[1];
            course[0] = c1;
            All_course_size++;
        }
        else
        {

            PA4::Course *temp = new PA4::Course[All_course_size + 1];
            for (int i = 0; i < All_course_size; i++)
            {
                temp[i] = course[i];
            }
            temp[All_course_size] = c1;
            All_course_size++;

            delete[] course;
            course = new PA4::Course[All_course_size];
            for (int i = 0; i < All_course_size; i++)
            {
                course[i] = temp[i];
            }

            delete[] temp;
        }
    }
}

void SchoolManagerSystem::selectCourse()
{
    string input, name, code;
    int choice, index = -1;

    cin.ignore();
    getline(cin, input);
    code = input.substr(0, input.find_first_of(' '));
    name = input.substr(input.find_first_of(' ') + 1);

    for (int i = 0; i < All_course_size; ++i)
    {
        if (name == course[i].getName() && code == course[i].getCode())
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        do
        {
            cout << "0 up\n";
            cout << "1 delete_course\n";
            cout << "2 list_students_registered_to_the_selected_course\n";

            cin >> choice;

            if (choice == 0)
            {
                break;
            }

            if (choice == 1)
            {
                PA4::Course *temp = new PA4::Course[All_course_size];

                for (int i = 0; i < index; i++)
                {
                    temp[i] = course[i];
                }

                for (int i = index + 1; i < All_course_size; i++)
                {
                    temp[index++] = course[i];
                }

                All_course_size--;
                delete[] course;

                course = new PA4::Course[All_course_size];
                for (int i = 0; i < All_course_size; i++)
                {
                    course[i] = temp[i];
                }

                int hangiogrenci, kacinciders;
                for (int i = 0; i < All_student_size; i++)
                {
                    for (int j = 0; j < student[i].getStudentCourseSize(); j++)
                    {
                        if (student[i].course[j].getName() == name && student[i].course[j].getCode() == code)
                        {

                            hangiogrenci = i;
                            kacinciders = j;

                            PA4::Course *temp = new PA4::Course[student[hangiogrenci].getStudentCourseSize()];
                            for (int k = 0; k < kacinciders; k++)
                            {
                                temp[k] = student[hangiogrenci].course[k];
                            }

                            for (int m = kacinciders + 1; m < student[hangiogrenci].getStudentCourseSize(); m++)
                            {
                                temp[kacinciders++] = student[i].course[m];
                            }

                            student[hangiogrenci].DecreaseCourseSize();
                            delete[] student[hangiogrenci].course;
                            student[hangiogrenci].course = new PA4::Course[student[hangiogrenci].getStudentCourseSize()];
                            for (int j = 0; j < student[hangiogrenci].getStudentCourseSize(); j++)
                            {
                                student[hangiogrenci].course[j] = temp[j];
                            }
                        }
                    }
                }

                break;
            }
            if (choice == 2)
            {
                if (course[index].student == nullptr)
                    course[index].SetCourseStudentSize(0);

                for (int j = 0; j < course[index].getCourseStudentSize(); j++)
                {

                    cout << course[index].student[j].getName() << " " << course[index].student[j].getId() << endl;
                }
            }

        } while (1);
    }
}
