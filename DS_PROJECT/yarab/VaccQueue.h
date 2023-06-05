#pragma once
#include <iostream>
using namespace std;

class VaccQueue
{
	int* wait_arr;
	int size, count;
	int front, back;
	int wait_list_num = 0;
public:
	VaccQueue();
	int Length();
	void enqueue(int ID);
	void dequeue();
	int Front();
	bool isempty();
	int q_num();
	bool isfull();
	void vacdisplayall();
	void extend();
	~VaccQueue();
};

