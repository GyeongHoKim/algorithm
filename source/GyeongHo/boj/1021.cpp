#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d1;
    int n, m, count = 0;
    cin >> n >> m;

    for (int i = 1; i < n + 1; ++i)
        d1.push_back(i);

    while (m--) {
        int content, index;
        cin >> content;

        for (int i = 0; i < d1.size(); ++i) {
            if (d1[i] == content)
                index = i;
        }

        if (index <= d1.size() / 2) {
            count +=  index;
            rotate(d1.begin(), d1.begin() + index, d1.end());
        }
        else {
            count += d1.size() - index;
            for (int i = 0; i < d1.size() - index; ++i) {
                d1.push_front(d1.back());
                d1.pop_back();
            }
        }
        d1.pop_front();
    }

    cout << count;
    return 0;

}