#include<iostream>
#include"macro.h"
#include"struct.h"
#include"global.h"
#include"function.h"
using namespace std;
int course_num;
int student_num;
Course *course;
Student *stu;
int **graph;
Dye *dye_node;
int dye_num;
int *course_amount;
float decision_vector[] = {0.5, 0.3, 0.15, 0.05};

void main()
{
	input_course(course_num, FILE1);
	course = new Course[course_num];
	course_amount = new int[course_num];
	for (int i = 0; i < course_num; i++)
	{
		course_amount[i] = 0;
	}
	input_course2(course_num, course, FILE1);
	input_student(student_num, FILE2);
	stu = new Student[student_num];
	input_student2(student_num, stu, FILE2);

	graph = new int*[course_num];

	for (int i = 0; i < course_num; i++)
	{
		graph[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++)
		{
			graph[i][j] = 0;
		}
	}

	dye_node = new Dye[course_num+1];
	dye_num = 0;
	graph_init();
	dye_node[0].color = 1;
	int id;
	while (dye_num != course_num)
	{
		id = update();
		dye_insert(id);
	}
	expand();
	output();
	system("pause");
}