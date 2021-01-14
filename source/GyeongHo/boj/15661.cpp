#include <iostream>
using namespace std;

int N, MIN = 987654321;
bool check[20] = {false};
int stats[20][20];

void DFS(int cnt, int pos, int end)
{
	if(cnt == end) {
		int start = 0; int link;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j) {
				if(check[i] == true && check[j] == true)
					start += stats[i][j];
				if(check[i] == false && check[j] == false)
					link += stats[i][j];
			}
		int temp = start - link;
		if(temp < 0) temp = -temp;
		if(MIN > temp) MIN = temp;
		return;
	}

	for(int i = pos; i < N - 1; ++i) {
		check[i] = true;
		DFS(cnt + 1, i + 1, end);
		check[i] = false;
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> stats[i][j];

	for(int i = 2; i < N; ++i)
		DFS(0, 0, i);

	cout << MIN;
	return 0;
}
