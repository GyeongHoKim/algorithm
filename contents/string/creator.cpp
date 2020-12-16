#include <iostream>
#include <string>
using namespace std;

int main()
{
    string t("Hello!");
    const char* p1 = "Hello!";
    const char* p2 = p1+6;

    string s1;
    string s2("Hello!");
    string s3("Hello!", 2);
    string s4(5, 'H');
    string s5(t.begin(), t.end());
    string s6(p1, p2);

    cout << "s(): " << s1 << endl;
    cout << "s2(sz): " << s2 << endl;
    cout << "s3(sz, n): " << s3 << endl;
    cout << "s4(n, c): " << s4 << endl;
    cout << "s5(iter1, iter2): " << s5 << endl;
    cout << "s6(p1, p2): " << s6 << endl;

    return 0;
}