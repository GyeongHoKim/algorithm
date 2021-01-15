#include <iostream>

using namespace std;

int seq[21];
int n, s;

int solve()
{
	int ans = 0;
	for(int i = 1; i < (1 << n); i++)
	{
		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			if(i & (1 << j))
			{
				sum += seq[j];
			}
		}
		if(sum == s)
		{
			ans++;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> s;
	
	for(int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}
	
	cout << solve();
	
}