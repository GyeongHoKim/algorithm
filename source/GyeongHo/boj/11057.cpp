#include <iostream>
#define MOD 10007
using namespace std;

int D[1001][10] = {0};

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < 10; ++i)
		D[1][i] = 1;

	for (int i = 2; i <= N; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = j; k < 10; ++k)
				D[i][k] = (D[i][k] + D[i - 1][j]) % MOD;

	int num = 0;
	for (int i = 0; i < 10; ++i)
		num = (num + D[N][i]) % MOD;

	cout << num;
	return 0;
}
