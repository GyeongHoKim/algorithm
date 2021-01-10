#include <iostream>
#include <vector>
using namespace std;

int MIN = 987654321;
int N;
int S[20][20];

void updateMin(vector<int>& team1, vector<int>& team2)
{
	int sum1 = 0, sum2 = 0;
	int diff;

	for(int i = 0; i < N/2; ++i) {
		for(int j = 0; j < N/2; ++j) {
			if(i == j) continue;
			sum1 += S[team1[i]][team1[j]];
			sum2 += S[team2[i]][team2[j]];
		}
	}
	diff = sum1 - sum2;
	if(diff < 0) diff = -diff;
	if(MIN > diff) MIN = diff;
}

void score(void)
{
	vector<int> team1, team2;
	for(int bitMask = 0; bitMask < (1 << N); ++bitMask) {
		team1.clear();
		team2.clear();
		for(int i = 0; i < N; ++i) {
			if(bitMask & (1 << i)) team1.push_back(i);
			else team2.push_back(i);
		}
		if(team1.size() > N/2 || team2.size() > N/2) continue;
		updateMin(team1, team2);
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> S[i][j];
	score();
	cout << MIN;
	return 0;
}
