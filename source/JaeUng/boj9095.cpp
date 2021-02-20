#include <bits/stdc++.h>

using namespace std;

int memo[12] = { 0, 1, 2, 4 };
int n;

void dp()
{
    for (int i = 4; i <= n; i++) memo[i] = memo[i-3] + memo[i-2] + memo[i-1];
    cout << memo[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        dp();
    }
}