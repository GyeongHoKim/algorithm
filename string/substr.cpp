#include <iostream>
#include <string>
using namespace std;

int main()
{
	string t("Hello!");
	string s1,s2,s3,s4,s5;

	s1 = t.substr(0);
	s2 = t.substr(0, string::npos);
	s3 = t.substr(0,2);
	s4 = t.substr(2,3);
	s5 = t.substr(2, string::npos);

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;

	return 0;
}
