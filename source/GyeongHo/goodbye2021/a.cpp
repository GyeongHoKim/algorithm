#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num){
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    int prev = 2;
    cin >> n;
    if (n == 1) {
        cout << 6;
        return 0;
    }
    for (int i = 3; i <= n * n; ++i) {
        if (isPrime(i)) {
            if (prev * i > n) {
                cout << prev * i;
                return 0;
            }
            prev = i;
        }
    }
    return 0;
}