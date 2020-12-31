#include <iostream>
using namespace std;

char table[51][51];
int maxCount = 0;

void swap(char *c1, char *c2)
{
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void countColumnCandy(int size)
{
	for(int i = 0; i < size; ++i) {
		int count = 1;
		for(int j = 0; j < size; ++j) {
			if(table[i][j] == table[i][j + 1]) ++count;
			else {
				if(count > maxCount) maxCount = count;
				count = 1;
			}
		}
	}
}

void countRowCandy(int size)
{
	for(int i = 0; i < size; ++i) {
		int count = 1;
		for(int j = 0; j < size; ++j) {
			if(table[j + 1][i] == table[j][i]) ++count;
			else {
				if(count > maxCount) maxCount = count;
				count = 1;
			}
		}
	}
}

void bruteForce(int N)
{
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(j != N) {
				swap(table[i][j], table[i][j + 1]);
				countRowCandy(N);
				countColumnCandy(N);
				swap(table[i][j + 1], table[i][j]);
				
				swap(table[j][i], table[j + 1][i]);
				countRowCandy(N);
				countColumnCandy(N);
				swap(table[j + 1][i], table[j][i]);
			}
		}
	}		
}

int main()
{
	int N;
	cin >> N;

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> table[i][j];

	bruteForce(N);
	cout << maxCount << endl;

	return 0;
}
