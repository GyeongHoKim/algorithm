#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int D[3][100001], arr[3][100001];

int DP(int L, int i)
{
	if (D[L][i] != -1)
		return D[L][i];
	if (L == 0)
		return D[L][i] = max({DP(0, i - 1), DP(1, i - 1), DP(2, i - 1)});
	if (L == 1)
		return D[L][i] = max(DP(0, i - 1) + arr[L][i], DP(2, i - 1) + arr[L][i]);
	if (L == 2)
		return D[L][i] = max(DP(0, i - 1) + arr[L][i], DP(1, i - 1) + arr[L][i]);
}

int main()
{
	int T, n;
	cin >> T;
	while(T--) {
		memset(arr, 0, sizeof(arr));

		cin >> n;
		for(int i = 1; i <= 2; ++i)
			for(int j = 1; j <= n; ++j)
				cin >> arr[i][j];

		memset(D, -1, sizeof(D));
		D[0][1] = 0; D[1][1] = arr[1][1]; D[2][1] = arr[2][1];

		cout << max({DP(0, n), DP(1, n), DP(2, n)}) << "\n";
	}
	return 0;
}
