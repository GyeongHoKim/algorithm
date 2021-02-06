#include <bits/stdc++.h>

using namespace std;


int N;
int P[10001];
int memo[10001];

void dp()
{
    for(int i = 1; i <= N; i++)
    {
        memo[i] = INT_MAX;
        for(int j = 1; j <= i; j++)
        {
            memo[i] = min(memo[i], memo[i-j] + P[j]);
        }
    }
    cout << memo[N];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> P[i];
    dp();
}