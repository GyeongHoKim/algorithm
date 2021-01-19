#include <iostream>
#include <algorithm>
using namespace std;

int cache[1000001];
int N;

int main()
{
	cin >> N;
	cache[1] = 0;
	cache[2] = 1;

	for(int i = 3; i < N + 1; ++i) {
		cache[i] = 1 + cache[i - 1];
		if(i % 3 == 0) cache[i] = min(cache[i/3] + 1, cache[i]);
		if(i % 2 == 0) cache[i] = min(cache[i/2] + 1, cache[i]);
	}

	cout << cache[N];
	return 0;
}
