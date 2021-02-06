#include <bits/stdc++.h>

using namespace std;

#define mod 1000000000

int N;
int memo[101][10] = { {0},
                       {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                     };

void dp()
{
    for(int i = 2; i <= N; i++)
    {
        memo[i][0] = memo[i-1][1] % mod;
        for(int j = 1; j <= 8; j++)
        {
            memo[i][j] = (memo[i-1][j-1] + memo[i-1][j+1]) % mod;
        }
        memo[i][9] = memo[i-1][8] % mod;
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++) 
    {
        ans += memo[N][i];
        ans %= mod;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dp();
}