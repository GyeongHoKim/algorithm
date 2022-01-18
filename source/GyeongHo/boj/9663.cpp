#include <bits/stdc++.h>
using namespace std;
bool visited1[40];
bool visited2[40];
bool visited3[40];

int n;
int dfs(int cur)
{
    int ans = 0;
    if (cur == n)
        return 1;
    for (int i = 0; i < n; i++)
    {
        if (visited1[i] || visited2[i + cur] || visited3[cur - i + n - 1])
            continue;
        visited1[i] = 1;
        visited2[i + cur] = 1;
        visited3[cur - i + n - 1] = 1;
        ans += dfs(cur + 1);
        visited1[i] = 0;
        visited2[i + cur] = 0;
        visited3[cur - i + n - 1] = 0;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << dfs(0);
}