#include <iostream>
using namespace std;

char table[50][50];

void swap(char *c1, char *c2)
{
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

int chk(int row, int column, char color, int type)
{
	// type=0, compare row. type=1, compare column
	int max = 0;
}

int solution(int N);

int main()
{
	int C,N;
	cin >> C;
	cin >> N;

	while(C--) {
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				cin >> table[i][j];

		cout << solution(N) << endl;
	}

	return 0;
}
