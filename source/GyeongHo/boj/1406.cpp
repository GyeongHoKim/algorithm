#include <bits/stdc++.h>
using namespace std;

int N;

int print(list<char> &l)
{
	for (auto e : l)
		cout << e;
	return 0;
}

int main()
{
	string str;
	cin >> str;
	cin >> N;
	list<char> word(str.begin(), str.end());
	auto it = word.end();
	while (N--) {
		char op;
		cin >> op;
		switch(op) {
		case 'L':
			if (it != word.begin()) --it;
			break;
		case 'D':
			if (it != word.end()) ++it;
			break;
		case 'B':
			if (it != word.begin()) it = word.erase(--it);
			break;
		default:
			cin >> op;
			word.insert(it, op);
			break;
		}
	}
	
	print(word);

	return 0;
}
