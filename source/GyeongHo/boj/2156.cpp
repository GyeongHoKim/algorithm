#include <iostream>
#include <algorithm>
using namespace std;

int D[10001][3];
int arr[10001];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	D[1][0] = 0; D[1][1] = arr[1];D[2][0] = arr[1]; D[2][1] = arr[2]; D[2][2] = arr[1] + arr[2];
	for (int i = 3; i <= n; ++i) {
		D[i][0] = max({D[i - 1][2], D[i - 1][1], D[i - 1][0]});
		D[i][2] = D[i - 1][1] + arr[i];
		D[i][1] = D[i - 1][0] + arr[i];
	}

	cout << max({D[n][0], D[n][1], D[n][2]});
	return 0;
}
