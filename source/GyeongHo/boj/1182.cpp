#include <iostream>
using namespace std;

int arr[20];
int N, S, cnt = 0;

int fullySearch(int N, int S)
{
	int count = 0;
	for(int i = 1; i < (1 << N); ++i) {
		int sum = 0;
		for(int j = 0; j < N; ++j)
			if(i & (1 << j))
				sum += arr[j];
		if(sum == S)
			++count;
	}

	return count;
}

void dfs(int cur, int total)
{
	if (cur >= N) {
		if (total == S)
			cnt++;
		return;
	}
	dfs(cur + 1, total);
	dfs(cur + 1, total + arr[cur]);
}

int main()
{
	cin >> N >> S;
	for(int i = 0; i < N; ++i)
		cin >> arr[i];

	cout << fullySearch(N, S);
	return 0;
}
