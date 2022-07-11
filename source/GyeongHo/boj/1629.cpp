#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long recursion(long long a, long long b, long long c) {
    if (b == 0)
        return 1;
    long long half = recursion(a, b / 2, c) % c;
    long long result = half * half % c;
    if (b & 1)
        return result * a % c;
    else
        return result;
}

long long forLoop(long long a, long long b, long long c) {
    long long result = 1;
    while (b) {
        if (b & 1)
            result = result * a % c;
        a = a * a % c;
        b = b >> 1;
    }
    return result;
}

int main() {
    cin >> a >> b >> c;
    cout << recursion(a, b, c);
    //cout << forLoop(a, b, c);
    return 0;
}