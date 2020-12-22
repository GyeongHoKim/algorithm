#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks)
{
	for(vector<int>::const_iterator iter = clocks.begin(); iter < clocks.end(); ++iter)
		if(*iter != 12) return false;
	return true;
}

void push(vector<int>& clocks, int swtch)
{
	for(int clock = 0; clock < CLOCKS; ++clock)
		if(linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if(clocks[clock] == 15) clocks[clock] = 3;
		}
}

int solve(vector<int>& clocks, int swtch)
{
	if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for(int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch +1)); // 현재 카운트 수 + 재귀함수에 현재 누른 스위치의 다음 스위치에 대한 카운트 수 + 반복
		push(clocks, swtch);
	}
	
	return ret;
}

int main()
{
	int C;
	vector<int> clocks(16);
	
	cin >> C;
	while(C--) {
		for(int i = 0; i < 16; ++i)
			cin >> clocks[i];
		
		cout << solve(clocks, 0) << endl;
	}
	
	return 0;
}