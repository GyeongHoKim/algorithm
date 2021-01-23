#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int W[11][11];
bool visit[11];
int ans = INT_MAX;

void dfs(int start, int prev, int cnt, int sum) //시작, 이전, 방문개수, 가중치 합 
{
    if (sum >= ans) return; //sum 값이 이미 이전까지의 답보다 클 경우
    if (cnt == N) //탐색 종료시
    {
        if(W[prev][start])
        {
            ans = min(ans, sum + W[prev][start]);
        }
        return;
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(!visit[i] && W[prev][i]) //방문하지 않았으며 방문 가능할경우
        {
            visit[i] = true;
            dfs(start, i, cnt + 1, sum + W[prev][i]); 
            visit[i] = false;
        }
    }
}

void solve()
{
    visit[1] = true;
    dfs(1, 1, 1, 0); // 모든 점을 방문해야 하기 때문에 시작점의 위치는 상관없음
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> W[i][j];
        }
    }
    solve();
}