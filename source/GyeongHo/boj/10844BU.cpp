#include <iostream>
#define MOD 1000000000
using namespace std;

int main()
{
	int n, i, j;
	int dp[101][11] = {0, };
	int sum = 0;

	cin >> n;

	for(i= 0; i <= 9; ++i)
		dp[1][i] = 1;

	for(i = 2; i <= n; ++i) {
		dp[i][0] = dp[i - 1][1];
		dp[i][10] = 0;
		for(j = 0; j <= 9; ++j)
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
	}
	
	for(i = 1; i <=9; ++i)
		sum = (sum + dp[n][i]) % MOD;

	cout << sum;

	return 0;
}
