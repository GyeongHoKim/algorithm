#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(1) {
        bool flag = true;
        string sentence;
        getline(cin, sentence, '\n');
        if (sentence.compare(".") == 0)
            break;
        
        stack<char> s;
        for (const char& c : sentence) {
            if (!flag)
                break;
            if (c == '[' || c == '(') {
                s.push(c);
            }
            else if (c == ']') {
                if (s.empty()) {
                    flag = false;
                }
                else {
                    if (s.top() == '[')
                        s.pop();
                    else
                        flag = false;
                }
            }
            else if (c == ')') {
                if (s.empty()) {
                    flag = false;
                }
                else {
                    if (s.top() == '(')
                        s.pop();
                    else
                        flag = false;
                }
            }
        }

        if (flag && s.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}