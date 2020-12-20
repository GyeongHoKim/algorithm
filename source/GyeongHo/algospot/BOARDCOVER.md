# BOARDCOVER

**문제**

![board](https://algospot.com/media/judge-attachments/2b7bfee35cbec2f4e799bb011ac18f69/03.png)

H*W 크기의 게임판이 있습니다. 게임판은 검은 칸과 흰 칸으로 구성된 격자 모양을 하고 있는데 이 중 모든 흰 칸을 3칸짜리 L자 모양의 블록으로 덮고 싶습니다. 이 때 블록들은 자유롭게 회전해서 놓을 수 있지만, 서로 겹치거나, 검은 칸을 덮거나, 게임판 밖으로 나가서는 안 됩니다. 위 그림은 한 게임판과 이를 덮는 방법을 보여줍니다.

게임판이 주어질 때 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.

**입력**

입력의 첫 줄에는 테스트 케이스의 수 C (C <= 30) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 2개의 정수 H, W (1 <= H,W <= 20) 가 주어집니다. 다음 H 줄에 각 W 글자로 게임판의 모양이 주어집니다. # 은 검은 칸, . 는 흰 칸을 나타냅니다. 입력에 주어지는 게임판에 있는 흰 칸의 수는 50 을 넘지 않습니다.

**출력**

한 줄에 하나씩 흰 칸을 모두 덮는 방법의 수를 출력합니다.

**예제 입력**

> 3  
> 3 7  
> #.....#  
> #.....#  
> ##...##  
> 3 7  
> #.....#  
> #.....#  
> ##..###  
> 8 10  
> ##########  
> #........#  
> #........#  
> #........#  
> #........#  
> #........#  
> #........#  
> ##########  

**예제 출력**

> 0  
> 2  
> 1514  

# 풀이

재귀호출을 통한 완전탐색을 해보자.  
subcase의 경우, "빈 칸을 블록이 덮을 수 있는가"  
기저사례의 경우, "모든 칸을 블록이 덮었는가"  

이 문제의 경우 함수 설계를 꽤 신경써야 하는데,  
블럭의 경우가 4가지이기 때문에 재귀함수 하나에 다 집어넣어버리면 for문이 4번 중첩되어 재귀호출과 break를 쓰기가 굉장히 힘들다.  
그래서 해당 칸에 블럭을 쌓을 수 있는지 없는지를 반환하는 set함수와 재귀호출이 담긴 cover함수 두 가지를 만들어야 한다.

``` c
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
```