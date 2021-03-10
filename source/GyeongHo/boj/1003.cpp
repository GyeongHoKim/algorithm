#include <iostream>
using namespace std;

int d0[41] = {0,};
int d1[41] = {0,};
int C;

int main()
{
	d0[0] = 1; d0[1] = 0;
	d1[0] = 0; d1[1] = 1;
	for (int i = 2; i <= 41; ++i) {
		d0[i] = d0[i - 2] + d0[i - 1];
		d1[i] = d1[i - 2] + d1[i - 1];
	}

	int n;
	cin >> C;
	while(C--) {
		cin >> n;
		cout << d0[n] << ' ' << d1[n] << "\n";
	}

	return 0;
}
