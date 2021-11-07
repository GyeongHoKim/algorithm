#include <bits/stdc++.h>
using namespace std;

int main()
{
	deque<int> d1;

	int n;
	string inst;
	cin >> n;
	while (n--) {
		cin >> inst;
		if (!inst.compare("push_front")) {
			int x;
			cin >> x;
			d1.push_front(x);
		}
		else if (!inst.compare("push_back")) {
			int x;
			cin >> x;
			d1.push_back(x);
		}
		else if (!inst.compare("pop_front")) {
			if (!d1.empty()) {
				cout << d1.front() << "\n";
				d1.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (!inst.compare("pop_back")) {
			if(!d1.empty()) {
				cout << d1.back() << "\n";
				d1.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if (!inst.compare("size")) {
			cout << d1.size() << "\n";
		}
		else if (!inst.compare("empty")) {
			cout << d1.empty() << "\n";
		}
		else if (!inst.compare("front")) {
			if (!d1.empty()) {
				cout << d1.front() << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else if (!inst.compare("back")) {
			if (!d1.empty())
				cout << d1.back() << "\n";
			else
				cout << -1 << "\n";
		}
		else
			cout << "wrong instruction" << "\n";
	}
	return 0;
}
