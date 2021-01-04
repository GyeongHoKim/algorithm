#include <iostream>
#include <algorithm>
using namespace std;

int W[10][10];
int arr[10] = {-1};

int lowCost(int N)
{
	int MIN = 10000000;
	int cost = 0;
	sort(arr, arr + N);
	do {
		for(int i = 0; i < N - 1; ++i) {
			cost += W[arr[i]][arr[i + 1]];
		}
		MIN = min(MIN, cost);
	}while(next_permutation(arr, arr + N));

	return MIN;
}

int main()
{
	int N;
	cin >> N;

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j)
			cin >> W[i][j];
		arr[i] = i;
	}

	cout << lowCost(N);
	return 0;
}
