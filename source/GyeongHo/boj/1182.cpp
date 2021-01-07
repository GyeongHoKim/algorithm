#include <iostream>
using namespace std;

int arr[20];

int fullySearch(int N, int S)
{
	int count = 0;
	for(int i = 1; i < (1 << N); ++i) {
		int sum = 0;
		for(int j = 0; j < N; ++j)
			if(i & (1 << j))
				sum += arr[j];
		if(sum == S)
			++count;
	}

	return count;
}

int main()
{
	int N, S;
	cin >> N >> S;
	for(int i = 0; i < N; ++i)
		cin >> arr[i];

	cout << fullySearch(N, S);
	return 0;
}
