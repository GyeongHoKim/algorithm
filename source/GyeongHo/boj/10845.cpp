#include <bits/stdc++.h>
using namespace

class q
{
private:
	int arr[10001];
	int head = 0;
	int tail = 0;

public:
	int push(int num)
	{
		if (tail + 1 > 10001)
			return 0;
		arr[tail++] = num;
		return 1;
	}

	void pop()
	{
		if (++head > 10000)
			return 0;
		return 1;
	}

	int size()
	{
		return tail - head;
	}

	int empty()
	{
		if (tail == 0)
			return 1;
		return 0;
	}

	int front()
	{
		if (tail == 0)
			return -1;
		return arr[head];
	}

	int back()
	{
		if (tail == 0)
			return -1;
		return arr[tail - 1];

int main()
{
	q q1;
