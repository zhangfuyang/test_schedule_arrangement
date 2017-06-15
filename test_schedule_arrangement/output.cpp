#include <iostream>
#include "global.h"
#include "macro.h"
using namespace std;
int random_partion(int *p, int n)
{
	int idx = rand() % n;
	swap(p[idx], p[n - 1]);
	int i = -1;    //i表示最后一个小于p[n-1]的元素的位置  
	int j = 0;     //j用来扫描数组  
	for (j = 0; j<n; j++)
	{
		//将小于p[n-1]的数交换到前半部分  
		if (p[j]<p[n - 1])
		{
			swap(p[++i], p[j]);
		}
	}
	swap(p[++i], p[n - 1]);
	return i;
}

int getMaxK(int *p, int n, int k)
{
	int mid;
	if (k <= 0)
		return -1;
	if (n<k)
		return -1;
	mid = random_partion(p, n);   //对原数组进行一次划分  
	if (mid == n - k)      //如果mid==n-k，那么返回该值，这就是第k大的数  
		return p[mid];
	else if (mid<n - k)
		return getMaxK(p + mid + 1, n - mid - 1, k);  //如果mid<n-k，那么第k大的数在右半数组，而且仍然是第k大数  
	else
		return getMaxK(p, mid, k - (n - mid));   //如果mid>n-k，那么第k大的数在左半数组，且在左半数组中是第k-(n-mid)大的数  
}
void copy(int* from, int* to)
{
	int i;
	for (i = 0; i < course_num; i++)
	{
		to[i] = from[i];
	}
}
void expand()
{
	int k = 1;
	int num = -1, num2;
	int same = 0;
	int i;
	int id;
	int day;
	bool button = false;
	int *copy_list;
	copy_list = new int[course_num];
	copy(course_amount, copy_list);
	if (dye_node[course_num].color < TIME)
	{
		while (dye_node[course_num].color < TIME)
		{
			button = false;
			k = k % course_num;
			if (k == 0)
				k = course_num;
			num2 = num;
			num = getMaxK(copy_list, course_num, k);
			copy(course_amount, copy_list);
			if (num2 == num)
			{
				same++;
			}
			else
				same = 0;
			for (i = 0; i < course_num; i++)
			{
				if (course_amount[i] == num && same != 0)
				{
					same--;
				}
				else if (course_amount[i] == num && same == 0)
				{
					id = i;
					break;
				}
			}
			if (id == dye_node[1].id)
			{
				k++;
				continue;
			}
			for (i = 1; i <= course_num; i++)
			{
				if (button == true)
				{
					dye_node[i].color++;
				}
				if (dye_node[i].id == id)
				{
					dye_node[i].color++;
					button = true;
				}
			}
			k++;
		}
	}
	else if (dye_node[course_num].color > TIME)
	{

	}
}
int find_dye_id(int course_id)
{
	for (int i = 1; i <= course_num; i++)
	{
		if (dye_node[i].id == course_id)
			return i;
	}
}
void output()
{
	int i;
	int id;
	for (i = 1; i <= course_num; i++)
	{
		id = dye_node[i].id;
		cout << dye_node[i].id << " " << course[id].name << " " << dye_node[i].color << endl;
	}
	float basic;
	float J = 0;
	float each = 0;
	int j;
	int dye_id;
	for (i = 0; i < student_num; i++)
	{
		each = 0;
		if (stu[i].course_num == 1)
			continue;
		basic = 1.0 * (TIME - 1) / (stu[i].course_num - 1);
		j = 0;
		while (j != stu[i].course_num)
		{
			dye_id = find_dye_id(stu[i].course[j]);
			each += abs((dye_node[dye_id].color - (j * basic + 1)));
			j++;
		}
		each /= stu[i].course_num;
		J += each;
	}
	cout << J;
}