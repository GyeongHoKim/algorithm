#include <bits/stdc++.h>
using namespace std;

int arr[11];
int op[10];
int n, max_val = INT_MIN, min_val = INT_MAX;

int cal()
{
    int ret = arr[0];
    for (int i = 1; i < n; ++i) {
        switch(op[i - 1]) {
        case 0:
            ret += arr[i];
            break;
        case 1:
            ret -= arr[i];
            break;
        case 2:
            ret *= arr[i];
            break;
        case 3:
            ret /= arr[i];
            break;
        }
    }
    return ret;
}

int main()
{
    int idx = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < 4; ++i) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < tmp; ++j)
            op[idx++] = i;
    }

    do {
        int temp = cal();
        if (max_val < temp)
            max_val = temp;
        if (temp < min_val)
            min_val = temp;
    } while(next_permutation(op, op + n - 1));

    cout << max_val << '\n' << min_val;
    return 0;
}