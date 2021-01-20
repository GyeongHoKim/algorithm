#include <iostream>
using namespace std;

int MAX = -1;
int money[1000];

void dfs(int N, int cnt, int sum)
{
	if(cnt > N) return;
	if(cnt == N) {
		if(MAX < sum)
			MAX = sum;
		return;
	}

	for(int i = 0; i < N; ++i) {
		cnt += i + 1;
		sum += money[i];
		dfs(N, cnt, sum);
		cnt -= i + 1;
		sum -= money[i];
	}
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> money[i];

	dfs(N, 0, 0);

	cout << MAX;
	return 0;
}
