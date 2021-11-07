#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y;
    cin >> y;

    if (y % 4 == 0 && y % 100 != 0)
        cout << 1;
    else if (y % 400 == 0)
        cout << 1;
    else
        cout << 0;

    return 0;
}