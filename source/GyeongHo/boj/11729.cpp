#include <bits/stdc++.h>
using namespace std;

int dp[21];

void hanoi(int position, int target, int number)
{
    if (number == 1) {
        cout << position << ' ' << target << '\n';
        return;
    }
    int next = 6 - position - target;
    hanoi(position, next, number - 1);
    hanoi(position, target, 1);
    hanoi(next, target, number - 1);
    return;
}

int main()
{
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 21; ++i)
        dp[i] = dp[i - 1] * 2 + 1;

    cout << dp[n] << '\n';
    hanoi(1, 3, n);
    return 0;
}