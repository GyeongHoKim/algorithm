#include <iostream>
#define MOD 1000000009
using namespace std;

int D[1000001] = {0};

int main()
{
	int T, n;
	cin >> T;

	D[1] = 1; D[2] = 2; D[3] = 4;
	for(int i = 4; i <= 1000000; ++i)
		D[i] = (D[i - 3] + D[i - 2] + D[i - 1]) % MOD;

	while(T--) {
		cin >> n;
		cout << D[n] << "\n";
	}
	return 0;
}
