#include <bits/stdc++.h>
using namespace std;

int n, k;
int w[101];
int v[101];
int dp[101][100001];
void bu(int n, int k);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    bu(n, k);
    cout << dp[n][k];
}

void bu(int n, int k)
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (w[i] <= j)
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
        }
    }
}