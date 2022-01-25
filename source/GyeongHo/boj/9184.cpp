#include <bits/stdc++.h>
using namespace std;

int cache[21][21][21];

int dfs(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return dfs(20, 20, 20);
    int& ret = cache[a][b][c];
    if (ret != -1)
        return ret;
    if (a < b && b < c)
        return ret = dfs(a, b, c - 1) + dfs(a, b - 1, c -1) - dfs(a, b - 1, c);
    return ret = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c -1) - dfs(a - 1, b - 1, c - 1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    memset(cache, -1, sizeof(cache));
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            return 0;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << dfs(a, b, c) << '\n';
    }
    return 0;
}