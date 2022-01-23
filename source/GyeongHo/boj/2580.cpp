#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<pair<int, int>> pos;
int zeros = 0;
bool flag = false;

bool chk(int posy, int posx, int num)
{
    int sectory = posy / 3, sectorx = posx / 3;
    for (int i = 0; i < 9; ++i) {
        if (board[i][posx] == num && i != posy)
            return false;
        if (board[posy][i] == num && i != posx)
            return false;
    }
    for (int i = sectory * 3; i < sectory * 3 + 3; ++i) {
        for (int j = sectorx * 3; j < sectorx * 3 + 3; ++j) {
            if (i == posy && j == posx)
                continue;
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

void dfs(int cnt)
{
    if (cnt >= zeros) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        flag = true;
        return;
    }
    for (int n = 1; n < 10; ++n) {
        board[pos[cnt].first][pos[cnt].second] = n;
        if (chk(pos[cnt].first, pos[cnt].second, n))
            dfs(cnt + 1);
        if (flag)
            return;
    }
    board[pos[cnt].first][pos[cnt].second] = 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                pos.push_back({i, j});
                ++zeros;
            }
        }
    }
    dfs(0);
    return 0;
}