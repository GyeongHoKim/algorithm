#include <iostream>
#include <cstring>
using namespace std;

int n;
int cache[1001], A[1001]; //should give A[0] minus

int DP(int start)
{
	int& ret = cache[start];
	if(ret != -1) return ret;

	ret = 0;
	for(int next = start + 1; next <= n; ++next)
		if(A[start] < A[next])
			ret = max(ret, DP(next) + 1);
	return ret;
}

int main()
{
	cin >> n;
	memset(cache, -1, sizeof(cache));
	memset(A, -1, sizeof(A));
	for(int i = 1; i <= n; ++i)
		cin >> A[i];

	cout << DP(0);
	return 0;
}
