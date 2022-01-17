#include <iostream>
using namespace std;

int arr[7];
int n, m;

void dfs(int cnt, int prev)
{
	if (cnt >= m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = prev; i <= n; ++i) {
		arr[cnt] = i;
		dfs(cnt + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	dfs(0, 1);
	
	return 0;
}