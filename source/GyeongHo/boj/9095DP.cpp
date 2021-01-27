#include <iostream>
using namespace std;

int D[11] = {0};

int main()
{
	int T, n;
	cin >> T;

	D[1] = 1; D[2] = 2; D[3] = 4;
	for(int i = 4; i <= 11; ++i)
		D[i] = D[i - 3] + D[i - 2] + D[i - 1];

	while(T--) {
		cin >> n;
		cout << D[n] << "\n";
	}
	return 0;
}
