#include <iostream>
using namespace std;
//test for branch recognition

int arr[100001], cache[100001];

int DP(int n)
{
	for(int i = 2; i <= n; ++i)
		cache[i] = max(arr[i], cache[i - 1] + arr[i]);

	int MAX = -1;
	for(int i = 1; i <= n; ++i)
		MAX = max(MAX, cache[i]);

	return MAX;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];

	cache[1] = arr[1];

	cout << DP(n);
	return 0;
}
