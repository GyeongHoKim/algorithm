#include <iostream>
using namespace std;

int board[501][501];
bool TFboard[501][501] = {false};
int Ydir[4] = {1, 0, -1, 0};
int Xdir[4] = {0, 1, 0, -1};
int N, M, MAX = 0;

void solution(int four, int sum, int y, int x)
{
	if(four == 0) {
		if(sum > MAX) MAX = sum;
		sum = 0;
		return;
	}

	for(int type =0; type < 4; ++type) {
		int ny = y + Ydir[type];
		int nx = x + Xdir[type];
		if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if(TFboard[ny][nx] == false) {
			TFboard[ny][nx] = true;
			solution(four - 1, sum + board[ny][nx], ny, nx);
			TFboard[ny][nx] = false;
		}
	}
}

void fuckU(int y, int x) {
	int sum = 0;
	//ㅗ
	if(y - 1 >= 0 && x + 2 < M) {
		sum = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y - 1][x + 1];
		MAX = MAX < sum ? sum : MAX;
	}
	//ㅏ
	if(y + 2 < N && x + 1 < M) {
		sum = board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 1][x + 1];
		MAX = MAX < sum ? sum : MAX;
	}
	//ㅜ
	if(y + 1 < N && x + 2 < M) {
		sum = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1];
		MAX = MAX < sum ? sum : MAX;
	}
	//ㅓ
	if(y + 2 < N && x - 1 >= 0) {
		sum = board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 1][x - 1];
		MAX = MAX < sum ? sum : MAX;
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			cin >> board[i][j];

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			TFboard[i][j] = true;
			solution(3, board[i][j], i, j);
			TFboard[i][j] = false;
			fuckU(i, j);
		}
	}

	cout << MAX;
	return 0;
}
