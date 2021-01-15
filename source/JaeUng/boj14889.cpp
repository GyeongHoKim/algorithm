#include<iostream>
#include<algorithm>

#define MAX_INT 2147483647

using namespace std;

int s[21][21];
int steam[11], lteam[11];
int n;
int ans = MAX_INT;

int lsum()
{
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		for (int j = 1; j <= n / 2; j++)
		{
			if (i != j)
				sum += s[lteam[i]][lteam[j]];
		}
	}
	return sum;
}

int ssum()
{
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
	{
		for (int j = 1; j <= n/2; j++)
		{
			if (i != j)
				sum += s[steam[i]][steam[j]];
		}
	}
	return sum;
}

void go(int order, int nst, int nlt)
{
	if (nst == n / 2 && nlt == n / 2) // 인원이 정확하게 나뉘어진 경우
	{
		int tmp = abs(ssum(n) - lsum(n));
		if (tmp < ans)
			ans = tmp;
		return;
	} 

	if (nst > n/2 || nlt > n/2) // 한쪽 팀의 인원이 절반 이상일 경우
		return;

	steam[nst + 1] = order; // order번째 사람이 스타트 팀으로 들어가는 경우
	go(order + 1, nst + 1, nlt);
	steam[nst + 1] = 0;

	lteam[nlt + 1] = order; // order번째 사람이 링크 팀으로 들어가는 경우
	go(order + 1, nst, nlt+1);
	lteam[nlt + 1] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> s[i][j];
		}
	}
	go(1,0,0);
	cout << ans;
}