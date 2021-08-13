#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp < x)
			cout << tmp << ' ';
	}
	return 0;
}
