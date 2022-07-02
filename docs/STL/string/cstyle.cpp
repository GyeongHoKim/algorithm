#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("Hello!");
    const char *sz;
    const char *buf;

    sz = s.c_str();
    buf = s.data();

    cout << "string that ends with null: " << sz << endl;
    cout << "string that does not end with null: ";
    for(int i = 0; i < 6; ++i)
        cout << buf[i];
    cout << endl;

    return 0;
}