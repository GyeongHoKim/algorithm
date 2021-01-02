#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int arr[8];
bool visited[8] = {false};

void permutation(int N, int M)
{
	if(M == 0) {
		for(vector<int>::const_iterator iter = v.begin(); iter < v.end(); ++iter)
			cout << *iter << ' ';
		cout << "\n";
		return;
	}

	int index;
	for(index = N; index >= 0; --index)
		if(visited[index]) break;

	for(int i = index + 1; i < N; ++i) {
		if(visited[i]) continue;
		v.push_back(arr[i]);
		visited[i] = true;
		permutation(N, M - 1);
		v.pop_back();
		visited[i] = false;
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
