#include <iostream>
using namespace std;

int cnt[10001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        cnt[temp] += 1;
    }
    for (int i = 0; i < 10001; ++i)
        for (int j = 0; j < cnt[i]; ++j)
            cout << i << '\n';
    return 0;
}