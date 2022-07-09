#include <bits/stdc++.h>
using namespace std;

char building[1000][1000];
int distJ[1000][1000];
int distF[1000][1000];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int n, m;

int bfs(int start_y, int start_x, queue<pair<int, int>> qFire)
{
    queue<pair<int, int>> qJoe;
    qJoe.push({start_y, start_x});
    distJ[start_y][start_x] = 1;
    while (!qFire.empty()) {
        pair<int, int> cur = qFire.front(); qFire.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || building[ny][nx] != '.')
                continue;
            if (distF[ny][nx] != 0 && distF[cur.first][cur.second] + 1 >= distF[ny][nx])
                continue;
            qFire.push({ny, nx});
            distF[ny][nx] = distF[cur.first][cur.second] + 1;
        }
    }
    while(!qJoe.empty()) {
        pair<int, int> cur = qJoe.front(); qJoe.pop();
        if (cur.first == 0 || cur.first == n - 1 || cur.second == 0 || cur.second == m - 1)
            return distJ[cur.first][cur.second];
        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || building[ny][nx] != '.')
                continue;
            if (distJ[ny][nx] != 0 && distJ[cur.first][cur.second] + 1 >= distJ[ny][nx])
                continue;
            if (distF[ny][nx] != 0 && distJ[cur.first][cur.second] + 1 >= distF[ny][nx])
                continue;
            qJoe.push({ny, nx});
            distJ[ny][nx] = distJ[cur.first][cur.second] + 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int start_y, start_x;
        string line;
        queue<pair<int, int>> fire;
        cin >> m >> n;

        for (int i = 0; i < n; ++i) {
            memset(distJ[i], 0, sizeof(distJ[i]));
            memset(distF[i], 0, sizeof(distF[i]));
        }

        for (int i = 0; i < n; ++i) {
            cin >> line;
            for (int j = 0; j < m; ++j) {
                building[i][j] = line[j];
                if (building[i][j] == '*') {
                    fire.push({i, j});
                    distF[i][j] = 1;
                }
                if (building[i][j] == '@') {
                    start_y = i;
                    start_x = j;
                    building[i][j] = '.';
                }
            }
        }
        
        int result = bfs(start_y, start_x, fire);
        if (result != -1)
            cout << result << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }
}