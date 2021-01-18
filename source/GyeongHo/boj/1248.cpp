#include <iostream>
#include <vector>
using namespace std;

int N;
char S[10][10];
int list[21];
vector<int> ans;

bool trueIfPossible(int index)
{
	if(ans.size() == 0) return true;
	
	for(int i = 0; i < index; ++i) {
		if(S[i][i] == '+' && ans[i] <= 0) return false;
		if(S[i][i] == '-' && ans[i] >= 0) return false;
		if(S[i][i] == '0' && ans[i] != 0) return false;
		int sum = ans[i];
		for(int j = i+1; j < index; ++j) {
			sum += ans[j];
			if(S[i][j] == '+' && sum <= 0) return false;
			if(S[i][j] == '-' && sum >= 0) return false;
			if(S[i][j] == '0' && sum != 0) return false;
		}
	}

	return true;
}

bool dfs(int cnt)
{
	if(!trueIfPossible(cnt)) return false;

	if(cnt == N) {
		for(int i = 0; i < N; ++i)
			cout << ans[i] << ' ';
		return true;
	}

	for(int i = 0; i < 21; ++i) {
		ans.push_back(list[i]);
		if(dfs(cnt + 1)) return true;
		ans.pop_back();
	}

	return false;
}

int main()
{
	int tmp = -10;
	for(int i = 0; i < 21; ++i)
		list[i] = tmp++;

	cin >> N;
	for(int i = 0; i < N; ++i)
		for(int j = i; j < N; ++j)
			cin >> S[i][j];

	dfs(0);

	return 0;
}
