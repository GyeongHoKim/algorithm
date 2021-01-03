#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//자기자신을 빼면서 중복되는 수는 빼주되 N에서 제외시키지 않아야 함

vector<int> v;
vector<int> arr;

void permutation(int N, int M, int cnt)
{
	if(cnt == M) {
		for(vector<int>::const_iterator iter = v.begin(); iter < v.end(); ++iter)
			cout << *iter << ' ';
		cout << "\n";
		return;
	}

	int index;
	if(v.size()){
		for(index = 0; index < N; ++index)
			if(v.back() == arr[index]) break;
	}
	else index = 0;

	int prev = 0; // 각 경우에서 첫 번째의 경우는 제외
	for(int i = index; i < N; ++i) { // 자기자신부터 시작하게 만들어야 됨
		if(prev == arr[i]) continue;
		v.push_back(arr[i]);
		prev = v[cnt];
		permutation(N, M, cnt + 1);
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
	permutation(N, M, 0);

	return 0;
}
