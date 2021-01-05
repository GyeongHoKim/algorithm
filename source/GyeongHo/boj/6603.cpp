#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
bool visit[13] = {false};
vector<int> v;
int S[49];

void permutation(int cnt)
{
	if(cnt == k) {
		for(int i = 0; i < 6; ++i)
			cout << v[i] << ' ';
		cout << "\n";
		return;
	}

	int index;
	for(index = k; index > 0; --index)
		if(visit[index]) break;

	for(int i = index; i < k; ++i) {
		if(visit[i]) continue;
		visit[i] = true;
		v.push_back(S[i]);
		permutation(cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	while(1) {
		cin >> k;
		if(k == 0) break;
		for(int i = 0; i < k; ++i)
			cin >> S[i];

		sort(S, S + k);
		permutation(1);
	}

	return 0;
}
