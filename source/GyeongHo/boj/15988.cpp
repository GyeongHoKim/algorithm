#include <iostream>
#define MOD 1000000009
using namespace std;

long long D[1000001] = {0};

int main()
{
	int T, n;
	cin >> T;

	D[1] = 1; D[2] = 2; D[3] = 4;
	for(int i = 4; i <= 1000000; ++i)
		D[i] = D[i - 3] + D[i - 2] + D[i - 1];

	while(T--) {
		cin >> n;
		cout << D[n] % MOD << "\n";
	}
	return 0;
}
