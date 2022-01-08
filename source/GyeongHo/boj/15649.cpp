#include <iostream>
using namespace std;

int arr[8];
int visited[9];
int n, m;

void pick(int cnt)
{
	if (cnt >= m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i])
			continue;
		arr[cnt] = i;
		visited[i] = 1;
		pick(cnt + 1);
		visited[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	pick(0);
	return 0;
}