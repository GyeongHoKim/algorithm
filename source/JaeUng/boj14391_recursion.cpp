#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_INT 2147483647
#define MIN_INT -21474836487-1

using namespace std;

int paper[6][6];
bool bar[6][6]; //0 : 가로  1 : 세로
int ans;
int n, m;

int solve()
{
	bool check[6][6] = { false };
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m;j++)
		{ 
			if (check[i][j] == false)
			{
				int tmp = 0;
				int ti = i, tj = j;
				if (bar[ti][tj] == false)
				{
					while (bar[ti][tj] == false && tj <= m)
					{
						tmp = tmp * 10 + paper[ti][tj];
						check[ti][tj++] = true;
					}
				}
				else if (bar[ti][tj] == true)
				{
					while (bar[ti][tj] == true && ti <= n)
					{
						tmp = tmp * 10 + paper[ti][tj];
						check[ti++][tj] = true;
					}
				}
				ret += tmp;
			}
		}
	}
	return ret;
}

void set(int row,int col) // 각 
{
	if (row == n+1 && col == 1)
	{
		int tmp = solve();
		ans = max(ans, tmp);
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
	printf("%d",ans);
}