#include <iostream>
using namespace std;

int cache[1001][3], arr[1001][3];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 3; ++j) {
			cin >> arr[i][j];
			if(i == 1) cache[1][j] = arr[i][j];
		}
	}

	for(int i = 2; i <=n; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(j == 0) cache[i][j] = min(cache[i - 1][1] + arr[i][j], cache[i - 1][2] + arr[i][j]);
			if(j == 1) cache[i][j] = min(cache[i - 1][0] + arr[i][j], cache[i - 1][2] + arr[i][j]);
			if(j == 2) cache[i][j] = min(cache[i - 1][0] + arr[i][j], cache[i - 1][1] + arr[i][j]);
		}
	}

	int MIN = 1001;
	for(int i = 0; i < 3; ++i)
		MIN = min(MIN, cache[n][i]);

	cout << MIN;
	return 0;
}
