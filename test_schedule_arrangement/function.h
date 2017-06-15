#ifndef _FUNCTION_H_
#include <string>
using namespace std;
void input_course(int &course_num, const char* file);
void input_course2(int course_num, string* course, const char* file);
void input_student(int &student_num, const char* file);
int str2int(string str);
void input_student2(int student_num, Student *stu, const char* file);
#endif