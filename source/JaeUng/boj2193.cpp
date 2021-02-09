#include <bits/stdc++.h>

using namespace std;

int N;
long long memo[91][2] = { {0,},
                          {0, 1},//1
                          {1, 0} };//10

void dp()
{
    for(int i = 3; i <= N; i++)
    {
        memo[i][0] = memo[i-1][0] + memo[i-1][1];
        memo[i][1] = memo[i-1][0];
    }
    cout << memo[N][0] + memo[N][1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dp();
}