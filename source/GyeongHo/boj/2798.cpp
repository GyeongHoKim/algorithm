#include <iostream>
using namespace std;

int main()
{
    int n, m, *cards, MAX_SUM = 0;
    cin >> n >> m;
    cards = new int(n);

    for (int i = 0; i < n; ++i)
        cin >> cards[i];

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k) {
                int sum = cards[i] + cards[j] + cards[k];
                if (sum <= m)
                    MAX_SUM = max(MAX_SUM, sum);
            }
    cout << MAX_SUM;
    return 0;
}