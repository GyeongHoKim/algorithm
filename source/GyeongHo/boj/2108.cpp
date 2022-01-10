#include <iostream>
using namespace std;

int cnt[8001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int ans[4] = {0, 0, 0, 0};
    int n, tmp, max_num = -4001, min_num = 4001, max_freq = 0, flag = 1, min_flag = 2;
    double avgDiv, sum = 0.0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        sum += tmp;
        cnt[tmp + 4000] += 1;
        if (tmp < min_num)
            min_num = tmp;
        if (tmp > max_num)
            max_num = tmp;
        if (max_freq < cnt[tmp + 4000])
            max_freq = cnt[tmp + 4000];
    }
    
    avgDiv =  sum / n;
    if (avgDiv >= 0) {
        ans[0] = avgDiv + 0.5;
    }
    else {
        ans[0] = avgDiv - 0.5;
    }

    tmp = 0;
    for (int i = 0; i < 8001; ++i) {
        if (flag)
            tmp += cnt[i];
        if (cnt[i] == max_freq && min_flag-- > 0) {
            ans[2] = i - 4000;
        }
        if (n/2 <= tmp - 1 && flag) {
            ans[1] = i - 4000;
            flag = 0;
        }
    }
    ans[3] = max_num - min_num;
    if (n == 1) {
        ans[2] = ans[0];
    }
    for (int i = 0; i < 4; ++i)
        cout << ans[i] << '\n';

    return 0;
}