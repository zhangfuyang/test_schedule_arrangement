#pragma once
#ifndef _STRUCT_H_
#include <string>
using namespace std;

struct Student {
	string name;
	int course_num;
	int course[20];
};

struct Dye {
	int id;
	int color;
};

struct Course {
	string name;
	bool dye;
};
#endif
