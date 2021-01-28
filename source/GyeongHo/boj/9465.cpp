#include <iostream>
#include <algorithm>
using namespace std;

int cache[3][100001];
int arr[2][100001];

int main()
{
	int T,n;


	cin >> T;
	

	while(T--) {
		cin >> n;
		for(int i = 0; i < 2; ++i)
			for(int j = 1; j <= n; ++j)
				cin >> arr[i][j];

		cache[0][1] = 0; cache[1][1] = arr[1][1]; cache[2][1] = arr[2][1];
		for(int i = 2; i <= n; ++i) {
			cache[0][i] = max({cache[0][i - 1], cache[1][i - 1], cache[2][i -  1]});
			cache[1][i] = max(cache[0][i - 1], cache[2][i - 1]) + arr[1][i];
			cache[2][i] = max(cache[0][i - 1], cache[1][i - 1]) + arr[2][i];
		}
		cout << max({cache[0][n], cache[1][n], cache[2][n]}) << "\n";
	}

	return 0;
}
