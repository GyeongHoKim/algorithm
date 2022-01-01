#include <bits/stdc++.h>
using namespace std;

int visitedh[101][101];
int visitedc[101][101];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
char painting[101][101];
int n;

bool check(char color, char hc, int y, int x)
{
    if (y < 0 || y >= n || x < 0 || x >= n)
        return false;
    if (hc == 'h') {
        if (visitedh[y][x] != -1)
            return false;
        else if (color != painting[y][x])
            return false;
        else
            return true;
    }
    if (hc == 'c') {
        if (visitedc[y][x] != -1)
            return false;
        else if (color == 'B' && painting[y][x] != 'B')
            return false;
        else if (painting[y][x] == 'B' && color != 'B')
            return false;
        else
            return true;
    }
    return true;
}

void bfs(int posy, int posx, char hc, char color)
{
    queue<pair<int, int>> q;
    q.push({posy, posx});
    if (hc == 'h')
        visitedh[posy][posx] = 1;
    else
        visitedc[posy][posx] = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;
            if (!check(color, hc, ny, nx))
                continue;
            q.push({ny, nx});
            if (hc == 'h')
                visitedh[ny][nx] = 1;
            if (hc == 'c')
                visitedc[ny][nx] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin.ignore();
    for (int i = 0 ; i < n; ++i) {
        string sentence;
        getline(cin, sentence);
        for (int j = 0; j < n; ++j) {
            painting[i][j] = sentence[j];
            visitedh[i][j] = -1;
            visitedc[i][j] = -1;
        }
    }

    int human = 0, cow = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visitedh[i][j] == -1) {
                bfs(i, j, 'h', painting[i][j]);
                ++human;
            }
            if (visitedc[i][j] == -1) {
                bfs(i, j, 'c', painting[i][j]);
                ++cow;
            }
        }
    }
    cout << human << ' ' << cow;
    return 0;
}