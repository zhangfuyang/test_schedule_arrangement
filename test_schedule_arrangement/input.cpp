#include <iostream>
#include <fstream>
#include <string>
#include "struct.h"
#include "global.h"
using namespace std;

void input_course(int &course_num, const char* file)
{
	ifstream fp(file);
	if (fp.fail())
	{
		cout << "课程读入错误\n";
		system("pause");
		exit(0);
	}
	string str;
	int k = 0;
	while (getline(fp, str))
	{
		k++;
	}
	course_num = k;
	fp.close();
}
void input_course2(int course_num, string* course, const char* file)
{
	ifstream fp2(file);
	int k = 0;
	string str;
	while (getline(fp2, str))
	{
		course[k++] = str;
	}
	fp2.close();
}
int str2int(string str)
{
	int i, number = 0;
	i = 0;
	while (i < str.length())
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return number;
}
void input_student(int &student_num, const char* file)
{
	ifstream fp(file);
	if (fp.fail())
	{
		cout << "学生读入错误\n";
		system("pause");
		exit(0);
	}
	int k = 0;
	int num;
	string str;
	while (getline(fp, str))
	{
		k++;
		getline(fp, str);
		num = str2int(str);
		while (num != 0)
		{
			getline(fp, str);
			num--;
		}
	}
	student_num = k;
	fp.close();
}
void input_student2(int student_num, Student* stu, const char* file)
{
	ifstream fp(file);
	if (fp.fail())
	{
		cout << "学生读入错误\n";
		system("pause");
		exit(0);
	}
	string str;
	int k = 0, i;
	int num;
	int stu_course_num;
	while (getline(fp, str))
	{
		stu_course_num = 0;
		stu[k].name = str;
		getline(fp, str);
		num = str2int(str);
		stu[k].course_num = num;
		while (num != 0)
		{
			getline(fp, str);
			for (i = 0; i < course_num; i++)
			{
				if (course[i] == str)
				{
					stu[k].course[stu_course_num++] = i;
				}
			}
			num--;
		}
		k++;
	}
	fp.close();
}