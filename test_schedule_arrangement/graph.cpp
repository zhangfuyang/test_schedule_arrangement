#include <iostream>
#include <stdlib.h>
#include <time.h>  
#include "global.h"
#include "macro.h"
using std::cout;
using std::endl;
int graph_value(int x, int y)
{
	if (x > y)
	{
		return graph[x][y];
	}
	if (x < y)
	{
		return graph[y][x];
	}
	printf("Graph wrong!");
	system("pause");
	exit(0);
}
float cal_time(int id)
{
	int i;
	if (dye_node[0].color >= VECTER_SIZE)
	{
		int color;
		i = dye_num;
		color = dye_node[i].color;
		float sum1 = 0;
		float sum2 = 0;
		float sum3 = 0;
		float sum4 = 0;
		while (dye_node[i].color == color)
		{
			sum1 += graph_value(id, dye_node[i].id);
			i++;
		}
		sum1 *= decision_vector[0];
		color = dye_node[i].color;
		while (dye_node[i].color == color)
		{
			sum2 += graph_value(id, dye_node[i].id);
			i++;
		}
		sum2 *= decision_vector[1];
		color = dye_node[i].color;
		while (dye_node[i].color == color)
		{
			sum3 += graph_value(id, dye_node[i].id);
			i++;
		}
		sum3 *= decision_vector[2];
		color = dye_node[i].color;
		while (dye_node[i].color == color)
		{
			sum4 += graph_value(id, dye_node[i].id);
			i++;
		}
		sum4 *= decision_vector[3];
		return sum1 + sum2 + sum3 + sum4;
	}
	if (dye_node[0].color < VECTER_SIZE)
	{
		if (dye_node[0].color == 1)
		{
			float sum = 0;
			i = 0;
			while (i != dye_num)
			{
				i++;
				sum += graph_value(id, dye_node[i].id);
			}
			return sum;
		}
		if (dye_node[0].color == 2)
		{
			float sum1 = 0;
			float sum2 = 0;
			i = 0;
			while (i != dye_num && dye_node[i].color == 1)
			{
				i++;
				sum1 += graph_value(id, dye_node[i].id);
			}
			sum1 *= 0.75;
			while (i != dye_num && dye_node[i].color == 2)
			{
				i++;
				sum2 += graph_value(id, dye_node[i].id);
			}
			sum2 *= 0.25;
			return sum1 + sum2;
		}
		if (dye_node[0].color == 3)
		{
			float sum1 = 0;
			float sum2 = 0;
			float sum3 = 0;
			i = 0;
			while (i != dye_num && dye_node[i].color == 1)
			{
				i++;
				sum1 += graph_value(id, dye_node[i].id);
			}
			sum1 *= 0.6;
			while (i != dye_num && dye_node[i].color == 2)
			{
				i++;
				sum2 += graph_value(id, dye_node[i].id);
			}
			sum2 *= 0.3;
			while (i != dye_num && dye_node[i].color == 3)
			{
				i++;
				sum2 += graph_value(id, dye_node[i].id);
			}
			sum3 *= 0.1;
			return sum1 + sum2 + sum3;
		}
	}
}
void graph_init()
{
	int i, j, k;
	int x;
	int y;
	//表示课程
	for (i = 0; i < student_num; i++)
	{
		for (j = 0; j < stu[i].course_num-1; j++)
		{
			x = stu[i].course[j];
			for (k = j + 1; k < stu[i].course_num; k++)
			{
				y = stu[i].course[k];
				if (x < y)
				{
					graph[y][x]++;
				}
				else if (x > y)
				{
					graph[x][y]++;
				}
				else
				{
					cout << "一门课选两次？" << endl;
					system("pause");
					exit(0);
				}
			}
		}
	}
	int max = 0;
	int temp, maxid;
	for (i = 0; i < course_num; i++)
	{
		temp = 0;
		for (j = 0; j < i; j++)
		{
			temp += graph[i][j];
		}
		for (j = i + 1; j < course_num; j++)
		{
			temp += graph[j][i];
		}
		if (temp > max)
		{
			max = temp;
			maxid = i;
		}
	}
	dye_node[++dye_num].color = 1;
	dye_node[dye_num].id = maxid;
	course[maxid].dye = true;
	int color;
	int id;
	color = dye_node[dye_num].color;
	id = dye_node[dye_num].id;
	for (int i = 0; i < course_num; i++)
	{
		if (i == id)
			continue;
		if (i < id)
		{
			if (graph[id][i] == 0 && course[i].dye == false)
			{
				dye_num++;
				dye_node[dye_num].id = i;
				dye_node[dye_num].color = dye_node[id].color;
				course[i].dye = true;
			}
		}
		else
		{
			if (graph[i][id] == 0 && course[i].dye == false)
			{
				dye_num++;
				dye_node[dye_num].id = i;
				dye_node[dye_num].color = color;
				course[i].dye = true;
			}
		}
	}
}

int update()
{
	int minid;
	float min = 1000000;
	float temp;
	int t;
	srand((unsigned)time(NULL));
	while (1)
	{
		t = (int)(course_num - dye_num)*rand() / (RAND_MAX + 1);
		for (int i = 0; i < course_num; i++)
		{
			/*if (course[i].dye == false && t>2)
			{
				t--;
			}
			else if (course[i].dye == false && t <= 2)
			{
				return i;
			}*/
			if (course[i].dye == false)
			{
				return i;
			}
		}
	}
}


void dye_insert(int id)
{
	dye_num++;
	dye_node[dye_num].color = dye_node[dye_num - 1].color + 1;
	dye_node[dye_num].id = id;
	course[id].dye = true;
}
