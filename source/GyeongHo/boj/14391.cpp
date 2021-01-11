#include <iostream>
using namespace std;

int N, M;
int paper[4][4];

int countMax()
{
	int MAX = 0;
	int sum = 0;
	for(int bitMask = 0; bitMask < (1 << N * M); ++bitMask) {
		//horizonal traverse
		for(int i = 0; i < N; ++i) {
			int tmp = 1;
			for(int j = M - 1; j >= 0; --j) {
				if(~bitMask & (1 << (i * M + j))) {
					sum += tmp * paper[i][j];
					tmp *= 10;
				}
				else tmp = 1;
			}
		}
	
		//vertical traverse
		for(int i = 0; i < M; ++i) {
			int tmp = 1;
			for(int j = N - 1; j >= 0; --j) {
				if(bitMask & (1 << (j * M + i))) {
					sum += tmp * paper[j][i];
					tmp *= 10;
				}
				else tmp = 1;
			}
		}
		if(MAX < sum) MAX = sum;
		sum = 0;
	}
	return MAX;
}

int main()
{
	string temp;
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> temp;
		for(int j = 0; j < M; ++j) 
			paper[i][j] = static_cast<int>(temp[j] - '0');
	}
	cout << countMax();

	return 0;
}
