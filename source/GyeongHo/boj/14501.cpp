#include <iostream>
#include <algorithm>
using namespace std;

int N, MAX = -1;
int table[2][15];

void traverse(int day, int cost)
{
	if(day > N) return;

	MAX = max(MAX, cost);

	for(int i = day; i < N; ++i)
		traverse(i + table[0][i], cost + table[1][i]);
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> table[0][i] >> table[1][i];

	traverse(0, 0);

	cout << MAX;
	return 0;
}
