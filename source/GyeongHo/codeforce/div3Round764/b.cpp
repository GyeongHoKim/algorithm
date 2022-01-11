#include <iostream>
using namespace std;

bool chk(int a, int b, int c)
{
    if ((2 * b - c) % a == 0 &&  2 * b - c != 0)
        return true;
    if ((a + (c - a) / 2) % b == 0 && (c - a) % 2 == 0)
        return true;
    if ((2 * b - a) % c == 0 && 2 * b - a != 0)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (chk(a, b, c))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}