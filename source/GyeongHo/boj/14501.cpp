#include <iostream>
using namespace std;

int N, sum = 0, MAX = 0;
int table[2][15];

void traverse(int index, int prev)
{
	if(index > N) {
		if(MAX < sum - prev) MAX = sum - prev;
		sum = 0;
		return;
	}

	sum += table[1][index];
	traverse(index + table[0][index], table[1][index]);
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> table[0][i] >> table[1][i];

	for(int i = 0; i < N; ++i)
		traverse(i, 0);
	cout << MAX;
	return 0;
}
