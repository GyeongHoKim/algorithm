#include <iostream>
#include <cstring>
using namespace std;

int D[91];

int DP(int N)
{
	if(D[N] != -1) return D[N];
	return D[N] = D[N - 1] + D[N - 2];
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
