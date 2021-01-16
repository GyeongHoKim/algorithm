#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 20;
int min_dif = 1000;
int S[MAX][MAX];
int N;

int getStatDiff(vector<int>& start, vector<int>& link)
{
	int sum_s = 0;
	int sum_l = 0;
	for(int i = 0; i < start.size(); ++i)
		for(int j = 0; j < start.size(); ++j) {
			sum_s += S[start[i]][start[j]];
			sum_l += S[link[i]][link[j]];
		}
	return abs(sum_s - sum_l);
}

void dfs(vector<int>& start, vector<int>& link, int index)
{
	if(index == N) {
		if(start.size() != N / 2 || link != N / 2) return;
		min_dif = min(min_dif, getStatDiff(start, link));
		return;
	}

	start.push_back(index);
	dfs(start, link, index + 1);
	start.pop_back();

	link.push_back(index);
	dfs(start, link, index + 1);
	link.pop_back();
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> S[i][j];

	vector<int> start, link;
	dfs(start, link, 0);

	cout << min_dif;
	return 0;
}
