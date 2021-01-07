#include <iostream>
#include <string>
using namespace std;

int M, num, BIT = 0;
string input;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	cin >> M;
	while(M--) {
		input.clear();
		cin >> input;
		if(input == "add") {
			cin >> num;
			BIT |= (1 << num);
		}
		else if(input == "remove") {
			cin >> num;
			BIT &= ~(1 << num);
		}
		else if(input == "check") {
			cin >> num;
			if(BIT & (1 << num)) cout << 1;
			else cout << 0;
			cout << "\n";
		}
		else if(input == "toggle") {
			cin >> num;
			BIT ^= (1 << num);
		}
		else if(input == "all") {
			BIT |= ~(1 << 21);
		}
		else if(input == "empty") {
			BIT &= 0;
		}
	}

	return 0;
}
