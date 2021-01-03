#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int arr[N];

	for(int i = 1; i < N + 1; ++i)
		arr[i - 1] = i;

	do {
		for(int i = 0; i < N; ++i)
			cout << arr[i] << ' ';
		cout << "\n";
	}while(next_permutation(arr, arr + N));

	return 0;
}
