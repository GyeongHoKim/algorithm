#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//자기자신을 빼면서 중복되는 수는 빼줘야 함

vector<int> v;
int arr[8];

void permutation(int N, int M)
{
	if(M == 0) {
		for(vector<int>::const_iterator iter = v.begin(); iter < v.end(); ++iter)
			cout << *iter << ' ';
		cout << "\n";
		return;
	}

	for(int i = 0; i < N; ++i) {
		v.push_back(arr[i]);
		permutation(N, M - 1);
		v.pop_back();
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);

	permutation(N, M);

	return 0;
}
