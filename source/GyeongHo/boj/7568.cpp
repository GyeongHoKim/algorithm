#include <bits/stdc++.h>
using namespace std;

int h[201];
int w[201];
int ans[201];
int n;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> h[i];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (w[i] < w[j] && h[i] < h[j])
                ans[i] += 1;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << ' ';
    
    return 0;
}