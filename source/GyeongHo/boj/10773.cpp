#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main()
{
    int k, sum = 0;
    cin >> k;
    while(k--){
        int num;
        cin >> num;
        if (!num)
            s.pop();
        else
            s.push(num);
    }
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}