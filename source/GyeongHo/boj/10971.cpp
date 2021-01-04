#include <iostream>
using namespace std;

int W[10][10];
bool visit[10];
int N, MIN = 987654321;

void costLow(int start, int loc, int sum, int cnt)
{
	if(cnt == N && start == loc) {
		if(MIN > sum) MIN = sum;
		return;
	}

	for(int i = 0; i < N; ++i) {
		if(W[loc][i] == 0) continue;

		if(visit[loc]) continue;
		visit[loc] = true;
		sum += W[loc][i];

		if(sum <= MIN) costLow(start, i, sum, cnt + 1);

		visit[loc] = false;
		sum -= W[loc][i];
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> W[i][j];

	for(int i = 0; i < N; ++i)
		costLow(i, 0, 0, 0);

	cout << MIN;
	return 0;
}
