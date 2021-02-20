#include <bits/stdc++.h>

using namespace std;

long long memo[100001][4] = { {0, 0, 0, 0}, 
							  {0, 1, 0, 0}, 
							  {0, 0, 1, 0}
							  {0, 1, 1, 1}
							};

void dp(int n)
{
	for(int i = 4; i <= n; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			memo[i][j] = (memo[i-j][1] + memo[i-j][2] + memo[i-j][3] - memo[i-j][j]) % 1000000009LL;
		}		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	dp(100000);
	while(T--)
	{
		int n;
		cin >> n;
		cout << (memo[n][1] + memo[n][2] + memo[n][3]) % 1000000009LL << '\n';
	}
}