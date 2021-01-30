#include <iostream>
#include <algorithm>

using namespace std;

int N;
int memo[1000001];

void dp(int N)
{
    for(int i = 2; i <= N; i++)
    {
        memo[i] = memo[i-1] + 1;
        if(i % 3 == 0) memo[i] = min(memo[i], memo[i/3] + 1);
        if(i % 2 == 0) memo[i] = min(memo[i], memo[i/2] + 1);
    }
    cout << memo[N];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dp(N);
}