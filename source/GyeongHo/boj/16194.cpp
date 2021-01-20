#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[1001];
int P[1001];
int N;

int main()
{
	cin >> N;
	for(int i = 1; i <= N; ++i)
		cin >> P[i];

	memset(cache, 10001, sizeof(cache));
	cache[0] = 0;
	cache[1] = P[1];

	for(int i = 2; i <= N; ++i)
		for(int j = 1; j <= i; ++j)
			cache[i] = min(cache[i], cache[i - j] + P[j]);

	cout << cache[N];
	return 0;
}
