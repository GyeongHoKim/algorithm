#include <iostream>
#include <cstring>
using namespace std;

long long D[91];

long long DP(int N)
{
	if(D[N] != -1) return D[N];
	return D[N] = DP(N - 1) + DP(N - 2);
}

int main()
{
	int n;
	cin >> n;

	memset(D, -1, sizeof(D));
	D[1] = 1; D[2] = 1;

	cout << DP(n);
	return 0;
}
