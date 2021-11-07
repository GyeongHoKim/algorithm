#include <bits/stdc++.h>
using namespace std;

class s
{
private:
    int arr[10000];
    int pos;
public:
    s(){ pos = -1; }
    ~s(){}
    int push(int i)
    {
        if (pos < 10000)
            arr[++pos] = i;
        else
            return 0;
        return 1;
    }
    int pop()
    {
        if (pos < 0)
            return -1;
        return arr[pos--];
    }
    int size()
    {
        return pos + 1;
    }
    int empty()
    {
        if (pos < 0)
            return 1;
        return 0;
    }
    int top()
    {
        if (pos < 0)
            return -1;
        return arr[pos];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    s s1;
    int n;
    cin >> n;
    while(n--) {
        string c;
        cin >> c;
        if (c == "push") {
            int num;
            cin >> num;
            if (!s1.push(num))
                cout << "ERROR with push";
        }
        else if (c == "pop") {
            cout << s1.pop() << "\n";
        }
        else if (c == "size") {
            cout << s1.size() << "\n";
        }
        else if (c == "empty")
        {
            cout << s1.empty() << "\n";
        }
        else if (c == "top") {
            cout << s1.top() << "\n";
        }
        else
            cout << "instruction error";
    }
    return 0;
}
