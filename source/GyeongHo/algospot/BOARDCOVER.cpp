#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int coverType[4][3][2] = {{{0,0}, {1,0}, {0,1}},
								{{0,0}, {0,1}, {1,1}},
								{{0,0}, {1,0}, {1,1}},
								{{0,0}, {1,0}, {1,-1}}};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for(int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if(ny < 0 || ny >= board.size() || nx < 0 || nx >=board[0].size()) // board를 받으면 H,W 인자를 굳이 받을 필요가 없네
			ok = false;
		else if((board[ny][nx] += delta) > 1)
			ok = false;
	}
	
	return ok;
}

int cover(vector<vector<int>>& board)
{
	int y = -1, x = -1;
	for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[i].size(); ++j)
			if(board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		if(y != -1) break;
	}
	
	if(y == -1) return 1;
	int ret = 0;
	for(int type = 0; type < 4; ++type) {
		if(set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}

int main()
{
	int C, H, W;
	string boardOneLine;
	cin >> C;
	while(C--) {
		cin >> H >> W;
		vector<vector<int>> board(H);
		
		// board배열 채우기
		int countWhite = 0;
		for(int i = 0; i < H; ++i) {
			cin >> boardOneLine;
			for(int j = 0; j < W; ++j) {
				if(boardOneLine[j] == '#') board[i].push_back(1);
				else { 
					board[i].push_back(0);
					++countWhite;
				}
			}
		}
		
		if(countWhite % 3 == 0)
			cout << cover(board) << endl;
		else
			cout << 0 << endl;
	}
	
	return 0;
}
