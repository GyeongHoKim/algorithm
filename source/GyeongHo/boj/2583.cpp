#include <bits/stdc++.h>
using namespace std;

int visited[100][100];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int m, n, k;

int bfs(int posy, int posx)
{
    int area = 1;
    queue<pair<int, int>> q;
    q.push({posy, posx});
    visited[posy][posx] = 1;
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx])
                continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
            ++area;
        }
    }
    return area;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a[100];
    cin >> m >> n >> k;
    for (int l = 0; l < k; ++l) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; ++i) {
            for (int j = x1; j < x2; ++j) {
                visited[i][j] = 1;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] == 0) {
                a[ret++] = bfs(i, j);
            }
        }
    }
    cout << ret << '\n';
    sort(a, a + ret);
    for (int i = 0; i < ret; ++i)
        cout << a[i] << ' ';
    
    
    return 0;
}