#include <iostream>
#include <vector>
using namespace std;

const int dx[8] = {-1, -1, -1,  1, 1, 1,  0, 0};
const int dy[8] = {-1,  0,  1, -1, 0, 1, -1, 1};

bool inRange(y, x)
{
	if(y > 5 || x > 5) return false;
	else return true;
}

bool hasWord(int y, int x, const string& word)
{
	if(!inRange(y, x)) return false;
	if(board[y][x] != word[0]) return false;
	if(word.size() == 1) return true;
	
	for(int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if(hasWord(nextY, nextX, word.substr(1)))
			return true;
	}
}

int main()
{
	int C, N, trueFlag = 0;
	char board[5][5];
	cin >> C;
	
	while(C--) {
		for(int i = 0; i < 5 ++i)
			for(int j = 0; j < 5; ++j)
				cint board[i][j];
		
		cint >> N;
		while(N--) {
			string word;
			cin >> word;
			
			for(int i = 0; i < 5; ++i)
				for(int j = 0; j < 5; ++j)
					if(hasWord(i, j, word))
						trueFlag = 1;
			if(trueFlag) cout << word << ' ' << "YES" << endl;
			else cout << word << ' ' << "NO" << endl;
		}
	}
	return 0;
}