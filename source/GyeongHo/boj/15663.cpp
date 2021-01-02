#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//자기자신을 빼면서 중복되는 수는 빼주되 N에서 제외시키지 않아야 함

vector<int> v;
vector<int> arr;
bool visited[8] = {false};

void permutation(int N, int M)
{
	if(M == 0) {
		for(vector<int>::const_iterator iter = v.begin(); iter < v.end(); ++iter)
			cout << *iter << ' ';
		cout << "\n";
		return;
	}

	for(int i = 0; i < N; ++i) {
		if(visited[i]) continue;
		visited[i] = true;
		v.push_back(arr[i]);
		permutation(N, M - 1);
		visited[i] = false;
		v.pop_back();
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int N, M, tmp;
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());
	permutation(N, M);

	return 0;
}
