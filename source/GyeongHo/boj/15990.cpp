#include <iostream>
#include <cstring>
using namespace std;

int D[100001][3];

int DP(int n)
{
	for(int i = 4; i <= n; ++i)
		for(int j = 1; j <= 3; ++j) {
			if(j == 1) D[i][j] = D[i - j][2] + D[i - j][3];
			if(j == 2) D[i][j] = D[i - j][1] + D[i - j][3];
			if(j == 3) D[i][j] = D[i - j][1] + D[i - j][2];
		}

	int sum = 0;
	for(int i = 1; i <= 3; ++i)
		sum += D[n][i];

	return sum;
}

int main()
{
	int C, n;
	cin >> C;
	while(C--) {
		cin >> n;
		memset(D, 0, sizeof(D));
		D[1][1] = 1; D[2][2] = 1; D[3][1] = 1; D[3][2] =1; D[3][3] = 1;

		cout << DP(n) << "\n";
	}

	return 0;
}
