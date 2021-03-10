#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int m, n;
int tomato[1000][1000] = {0,};
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

queue<pair<int, int>> q;

int bfs()
{
	int MAX = 1;
	while(!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int newY = pos.first + dy[i];
			int newX = pos.second + dx[i];
			if (newY >= 0 && newY < n && newX >= 0 && newX < m && tomato[newY][newX] == 0) {
				tomato[newY][newX] = tomato[pos.first][pos.second] + 1;
				q.push(make_pair(newY, newX));
				MAX = max(MAX, tomato[newY][newX]);
			}
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (tomato[i][j] == 0)
				return -1;
	return MAX - 1;
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> tomato[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (tomato[i][j] == 1)
				q.push(make_pair(i, j));

	cout << bfs();
	return 0;
}
