#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int W[11][11];

void solve()
{
    int ans = INT_MAX;
    int perm[20];
    for (int i = 1; i <= N; i++)
    {
        perm[i] = i;
    }   // 순열 생성

    do {
        int sum = 0;
        for (int i = 1; i < N; i++)
        {
            if (W[perm[i]][perm[i+1]]) 
                sum += W[perm[i]][perm[i+1]];
            else // 길이 존재하지 않을 경우 탐색 중지
            {    
                sum = 0;
                break;
            }
        }
        if (sum && W[perm[N]][perm[1]]) // 탐색 후 되돌아 오는 길의 가중치까지 더함
        { 
            sum += W[perm[N]][perm[1]];
            ans = min(ans, sum);
        }
    } while (next_permutation(perm + 1, perm + 1 + N));
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