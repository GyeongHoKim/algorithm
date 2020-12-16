#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int count = 0;

	while(cin >> str) {
		count++;
	}

	cout << count;

	return 0;
}
