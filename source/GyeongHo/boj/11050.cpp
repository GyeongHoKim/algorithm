#include <iostream>
using namespace std;

int dp[11][11];
int n, k;

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < min(i, k) + 1; ++j) {
            if ( j == 0 || i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][k];

    return 0;
}