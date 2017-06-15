#include<iostream>
#include"macro.h"
#include"struct.h"
#include"global.h"
#include"function.h"
using namespace std;
int course_num;
int student_num;
string *course;
Student *stu;
void main()
{
	input_course(course_num, FILE1);
	course = new string[course_num];
	input_course2(course_num, course, FILE1);
	cout << course_num;
	for (int i = 0; i < course_num; i++)
	{
		cout << course[i] << endl;
	}
	input_student(student_num, FILE2);
	stu = new Student[student_num];
	input_student2(student_num, stu, FILE2);
	system("pause");
}