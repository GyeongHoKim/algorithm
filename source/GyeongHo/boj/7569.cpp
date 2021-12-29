#include <bits/stdc++.h>
using namespace std;

int tomato[100][100][100];
int visited[100][100][100];
int dy[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int m, n, k;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;
    queue<tuple<int, int, int>> q;
    for (int z = 0; z < k; ++z) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> tomato[i][j][z];
                if (tomato[i][j][z] == 1) {
                    visited[i][j][z] = 0;
                    q.push({i, j, z});
                }
                else
                    visited[i][j][z] = -1;
            }
        }
    }
    
    while(!q.empty()) {
        tuple<int, int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 6; ++i) {
            int ny = get<0>(cur) + dy[i];
            int nx = get<1>(cur) + dx[i];
            int nz = get<2>(cur) + dz[i];
            if (ny >= n || ny < 0 || nx >= m || nx < 0 || nz >= k || nz < 0 || visited[ny][nx][nz] != -1 || tomato[ny][nx][nz] != 0)
                continue;
            tomato[ny][nx][nz] = 1;
            visited[ny][nx][nz] = visited[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push({ny, nx, nz});
        }
    }

    int ret = 0;
    for (int z = 0; z < k; ++z) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (tomato[i][j][z] == 0) {
                    cout << -1;
                    return 0;
                }
                ret = max(ret, visited[i][j][z]);
            }
        }
    }
    cout << ret;
    return 0;
}