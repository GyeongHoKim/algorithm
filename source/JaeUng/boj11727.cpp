#include <bits/stdc++.h>

using namespace std;

int n;
int memo[1001] = { 0, 1, 3 };

void dp()
{
    for(int i = 3; i <= n; i++)
        memo[i] = (memo[i-1] + 2*memo[i-2]) % 10007;
    cout << memo[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dp();
}