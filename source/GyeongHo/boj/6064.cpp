#include <iostream>
#include <vector>
using namespace std;

int LCM(int M, int N)
{
	int mul = M * N;
	while(N > 0) {
		int tmp = N;
		N = M % N;
		M = tmp;
	}
	return mul / M;
}

int solution(int M, int N, int x, int y)
{
	vector<int> traverseList;
	for(int i = 1; i <= total; ++i) {
		if(M == x)
			if(i % M == 0)
				traverseList.push_back(i);
		else
			if(i % M == x)
				traverseList.push_back(i);
	}
	
	for(vector<int>::iterator iter = traverseList.begin(); iter < traverseList.end(); ++iter) {
		if(N == y)
			if(*iter % N == 0)
				return *iter;
		else
			if(*iter % N == y)
				return *iter;
	}
	
	return -1;
}

int main()
{
	int C, M, N, x, y;
	cin >> C;

	while(C--) {
		cin >> M >> N >> x >> y;
		cout << solution(M, N, x, y) << endl;
	}

	return 0;
}
