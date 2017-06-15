#ifndef _FUNCTION_H_
#include <string>
using namespace std;
void input_course(int &course_num, const char* file);
void input_course2(int course_num, Course* course, const char* file);
void input_student(int &student_num, const char* file);
int str2int(string str);
void input_student2(int student_num, Student *stu, const char* file);
void graph_init();
int graph_value(int x, int y);
float cal_time(int id);
void dye_insert(int id);
int update();
void output();
int random_partion(int *p, int n);
int getMaxK(int *p, int n, int k);
void expand();
void copy(int* from, int* to);
#endif