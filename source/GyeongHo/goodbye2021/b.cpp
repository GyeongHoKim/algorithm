#include <bits/stdc++.h>
using namespace std;

bool pattern[9] = {false, true, false, false, true, false, false, true, true};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        if (pattern[(n - 1) % 9])
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}