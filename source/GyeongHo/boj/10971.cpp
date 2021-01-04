#include <iostream>
using namespace std;

int W[10][10];
int list[10];
int N, MIN = 1234567890;
bool visit[10] = {false};

void whereToGo(int cnt)
{
	int cost = 0;
	int tmp =0;
	if(cnt == N) {
		MIN = min(MIN, cost);
		return;
	}

	int prev = -1;
	for(int i = 0; i < N; ++i) {
		if(visit[i]) continue;
		if(prev > -1) {
			tmp = W[prev][list[i]];
			cost += tmp;
		}
		visit[i] = true;
		prev = list[i];
		whereToGo(cnt + 1);
		cost -= tmp;
		visit[i] = false;
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j)
			cin >> W[i][j];
		list[i] = i;
	}

	cout << MIN;
	return 0;
}
