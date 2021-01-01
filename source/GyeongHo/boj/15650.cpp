#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
bool chosen[9] = {false};

void combination(int N, int M)
{
	if(M == 0) {
		for(vector<int>::iterator iter = v.begin(); iter < v.end(); ++iter)
			cout << *iter << ' ';
		cout << "\n";
		return;
	}

	int index;
	for(index = 8; index > 0; --index) {
		if(chosen[index]) break;
	}

	for(int i = index + 1; i < N + 1; ++i) {
		chosen[i] = true;
		v.push_back(i);
		combination(N, M - 1);
		chosen[i] = false;
		v.pop_back();
	}
	return;
}

int main()
{
	int N, M;
	cin >> N >> M;
	combination(N, M);

	return 0;
}
