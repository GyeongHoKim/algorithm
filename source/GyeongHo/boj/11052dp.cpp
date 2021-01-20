#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int D[1001];
int p[1001];

int dp()
{
	for(int i = 1; i < N + 1; ++i)
		for(int j = 1; j < i + 1; ++j)
			D[i] = max(D[i], p[j] + D[i - j]);

	return D[N];
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; ++i)
		cin >> p[i];

	memset(D, -1, sizeof(D));
	D[0] = 0;

	cout << dp();
	return 0;
}
