#include <iostream>
#define MOD 9901
using namespace std;

long long cache[100001][3];

int main()
{
	int N;
	cin >> N;

	cache[1][0] = 1; cache[1][1] = 1; cache[1][2] = 1;

	for(int i = 2; i <= N; ++i) {
		cache[i][0] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2]) % MOD;
		cache[i][1] = (cache[i-1][0] + cache[i-1][2]) % MOD;
		cache[i][2] = (cache[i-1][0] + cache[i-1][1]) % MOD;
	}

	cout << (cache[N][0] + cache[N][1] + cache[N][2]) % MOD;
	return 0;
}
