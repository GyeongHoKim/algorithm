#include <iostream>
using namespace std;

int main()
{
    int T, n;
    cin >> T;
    while(T--) {
        int maxNum = 0;
        int minNum = INT_MAX;
        int tmp;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp < minNum)
                minNum = tmp;
            if (maxNum < tmp)
                maxNum = tmp;
        }
        cout << maxNum - minNum << '\n';
    }
    return 0;
}