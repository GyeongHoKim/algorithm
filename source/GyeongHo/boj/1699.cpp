#include <iostream>
using namespace std;

int cache[100001];

int DP(int N)
{
	if(cache[N] != 987654321) return cache[N];
	for(int i = 1; i * i<= N; ++i) {
		cache[N] = min(cache[N], DP(N - i * i) + 1);
	}
	
	return cache[N];
}

int main()
{
	int N;
	for(int i = 0; i <= 100000; ++i) cache[i] = 987654321;
	cache[0] = 0; cache[1] =1;
	cin >> N;

	cout << DP(N);
	return 0;
}
