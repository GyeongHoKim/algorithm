#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int h, w, n, y, x;
        cin >> h >> w >> n;

        if (n % h) {
            y = n % h;
            x = n / h + 1;
        }
        else {
            y = n;
            x = n / h; 
        }

        printf("%d%02d\n", y, x);
    }

    return 0;
}