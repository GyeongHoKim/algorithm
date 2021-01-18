#include<iostream>
#include<algorithm>

using namespace std;

int paper[6][6];
bool bar[6][6]; //0 : 가로  1 : 세로
int ans;
int n, m;

int solve()
{
	int ret = 0;
	for (int i = 1; i <= n; i++) // 가로 계산
	{
		int tmp = 0;
		for(int j = 1; j <= m; j++)
		{ 
			if (!bar[i][j])
			{
				tmp = tmp * 10 + paper[i][j];
				if (j == m || bar[i][j+1])
				{
					ret += tmp;
					tmp = 0;
				}	
			}
		}
	}
	for (int j = 1; j <= m; j++) // 세로 계산
	{
		int tmp = 0;
		for(int i = 1; i <= n; i++)
		{ 
			if (bar[i][j])
			{
				tmp = tmp * 10 + paper[i][j];
				if (i == n || !bar[i+1][j])
				{
					ret += tmp;
					tmp = 0;
				}	
			}
		}
	}
	return ret;
}

void set(int row,int col) // 각 칸이 가로인지 세로인지 정하기
{
	if (row == n+1 && col == 1)
	{
		ans = max(ans, solve());
		return;
	}

	if (col == m)
	{
		set(row + 1, 1);
		bar[row][col] = true;
		set(row + 1, 1);
		bar[row][col] = false;
	}
	else
	{
		set(row, col+1);
		bar[row][col] = true;
		set(row, col+1);
		bar[row][col] = false;
	}
}

int main()
{	
    scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &paper[i][j]);
		}
	}
	set(1,1);
	printf("%d\n", ans);
}