#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int forLoop(int i, int j)
{
    int result = 0;
    n = 1 << (n - 1);
    for (int k = n; k > 0; k >>= 1) {
        if (i < k && j < k)
            continue;
        else if (i >= k && j < k)
            result += k * k * 2;
        else if (i < k && j >= k)
            result += k * k;
        else
            result += k * k * 3;
        i %= k;
        j %= k;
    }
    return result;
}

int recursion(int n, int r, int c)
{
    if (n == 0)
        return 0;
    int half = 1 << (n - 1);
    if (r < half && c < half)
        return recursion(n - 1, r, c);
    else if (r < half && c >= half)
        return half * half + recursion(n - 1, r, c - half);
    else if (r >= half && c < half)
        return half * half * 2 + recursion(n - 1, r - half, c);
    else
        return half * half * 3 + recursion(n - 1, r - half, c - half);
}

int main()
{
    cin >> n >> r >> c;

    cout << forLoop(r, c);
    //cout << recursion(n, r, c);
}