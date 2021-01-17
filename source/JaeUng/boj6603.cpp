#include <iostream>
#include <algorithm>

using namespace std;

int num[14];
bool check[14];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    do {
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> num[i];
            check[i] = i > 6 ? 0 : 1;
        }
        do {
            for (int i = 1; i <= k; i++)
            {
                if (check[i]) { cout << num[i] << ' '; }
            }
            cout << '\n';
        } while (prev_permutation(check + 1, check + 1 + k));
        cout << '\n';
    } while(k);
}