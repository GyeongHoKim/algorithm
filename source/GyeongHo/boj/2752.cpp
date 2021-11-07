#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b) {
        if (a < c) {
            cout << b << ' ' << a << ' ' << c;
        }
        else {
            if (c > b)
                cout << b << ' ' << c << ' ' << a;
            else
                cout << c << ' ' << b << ' ' << a;
        }
    }
    else {
        if (b < c) {
            cout << a << ' ' << b << ' ' << c;
        }
        else {
            if (a < c)
                cout << a << ' ' << c << ' ' << b;
            else
                cout << c << ' ' << a << ' ' << b;
        }
    }

    return 0;
}