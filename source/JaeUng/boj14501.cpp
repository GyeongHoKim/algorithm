#include <iostream>
#include <climits>

using namespace std;

int N;
int T[16], P[16];
bool check[16];

int ans = INT_MIN;

void solve(int day, int cost)
{
    if (day > N)
    {
        ans = max(ans, cost);
        return;
    }

    if (day + T[day] <= N + 1)
    {
        solve(day + T[day], cost + P[day]);
    }
    solve(day + 1, cost);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }
    solve(1, 0);
    cout << ans;
}