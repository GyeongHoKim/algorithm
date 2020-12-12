#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("Hello!");
    char buf[100];

    s.copy(buf,s.length());
    buf[s.length()] = '\0';
    cout << "all string[copy(buf, n)]: " << buf << endl;
    s.copy(buf,4,2);
    buf[4] = '\0';
    cout << "part of string[copy(buf,n,off)]: " << buf << endl;

    return 0;
}