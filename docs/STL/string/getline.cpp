#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;

	cout << "enter two string: " << endl;
	getline(cin, s1);
	getline(cin, s2, '\n');
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;

	return 0;
}
