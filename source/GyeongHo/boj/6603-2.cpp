#include <iostream>
#define MAX 13
using namespace std;

int S[MAX];
int combination[MAX];
int k;

void dfs(int start, int depth)
{
	if(depth == 6) {
		for(int i = 0; i < 6; ++i)
			cout << combination[i] << ' ';
		cout << "\n";
		return;
	}

	for(int i = start; i < k; ++i) {
		combination[depth] = S[i];
		dfs(i + 1, depth + 1);
	}
}

int main()
{
	while(cin >> k && k) {
		for(int i = 0; i < k; ++i)
			cin >> S[i];
		
		dfs(0,0);
		cout << "\n";
	}

	return 0;
}
