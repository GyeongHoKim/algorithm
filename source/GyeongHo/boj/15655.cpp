#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool chosen[8] = {false};

void permutation(int N, int M, const vector<int>& v)
{
	if(M == 0) {
		for(int i = 0; i < N; ++i) {
			if(chosen[i])
				cout << v[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for(int i = 0; i < N; ++i) {
		if(chosen[i]) continue;
		chosen[i] = true;
		permutation(N, M - 1, v);
		chosen[i] = false;
	}

	return;
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> v(N);

	for(int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	permutation(N, M, v);
	
	return 0;
}
