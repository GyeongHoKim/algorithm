#include <iostream>
#include <string>
using namespace std;

string chessBoard[50];

const string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

const string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

int count_repaint_by_window(int window_y, int window_x)
{
    int countW = 0, countB = 0;
    for (int i = window_y; i < window_y + 8; ++i) {
        for (int j = window_x; j < window_x + 8; ++j) {
            if (WB[i - window_y][j - window_x] != chessBoard[i][j])
                ++countW;
        }
    }
    for (int i = window_y; i < window_y + 8; ++i) {
        for (int j = window_x; j < window_x + 8; ++j) {
            if (BW[i - window_y][j - window_x] != chessBoard[i][j])
                ++countB;
            if (countB > countW)
                return countW;
        }
    }

    return countB;
}

int main()
{
    int n, m, min_count = 2501;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> chessBoard[i];

    for (int i = 0; i <= n - 8; ++i) {
        for (int j = 0; j <= m - 8; ++j) {
            min_count = min(min_count, count_repaint_by_window(i, j));
        }
    }

    cout << min_count;
    return 0;
}