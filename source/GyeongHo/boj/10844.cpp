#include <iostream>
#include <cstring>
using namespace std;

int cache[101][10];
int MOD = 1000000000;

int DP(int n, int L)
{
	int& ret = cache[n][L];
	if(ret != -1) return ret;
	if(L == 9) return ret = DP(n-1, L-1) % MOD;
	if(L == 0) return ret = DP(n-1, L+1) % MOD;
	return ret = (DP(n-1, L-1) + DP(n-1, L+1)) % MOD;
}

int main()
{
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for(int i = 1; i < 10; ++i)
		cache[1][i] = 1;
	cache[1][0] = 0;

	int sum = 0;
	for(int i = 0; i < 10; ++i)
		sum += DP(n, i);
	cout << sum;
	return 0;
}
