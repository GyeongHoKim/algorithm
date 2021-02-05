#include <iostream>
#include <cstring>
using namespace std;

int N;
int D[501][501], arr[501][501];

int DP(int i, int j)
{
	if( i > N) return 0;
	int& ret = D[i][j];
	if(ret != -1) return ret;
	return ret = max(arr[i][j] + DP(i + 1, j), arr[i][j] + DP(i + 1, j + 1));
}

int main()
{
	memset(D, -1, sizeof(D));
	cin >> N;
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= i; ++j)
			cin >> arr[i][j];

	cout << DP(1, 1);
	return 0;
}
