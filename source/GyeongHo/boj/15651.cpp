#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void permutation(int M, int N)
{
	if(N == 0) {
		for(vector<int>::iterator iter = v.begin(); iter < v.end(); ++iter) {
			cout << *iter;
			if(iter + 1 != v.end())
				cout << ' ';
		}
		cout << endl;
		return;
	}

	for(int i = 1; i < M + 1; ++i) {
			v.push_back(i);
			permutation(M, N - 1);
			v.pop_back();
	}

	return;
}

int main()
{
	int M, N;

	cin >> M >> N;
	permutation(M, N);
	
	return 0;
}
