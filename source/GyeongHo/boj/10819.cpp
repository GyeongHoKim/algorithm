#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	int N, MAX = 0;
	int *arr;
	cin >> N;

	arr = new int[N];
	for(int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);
	do {
		int tmp = 0;
		for(int i = 0; i < N - 1; ++i)
			tmp += abs(arr[i] - arr [i + 1]);
		MAX = max(tmp, MAX);
	}while(next_permutation(arr, arr + N));

	cout << MAX;
	return 0;
}
