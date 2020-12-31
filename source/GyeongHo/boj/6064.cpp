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

// 인덱스 구하는 루프문 하나 구하고 인덱스 구한 다음에는 M씩 점프. 그 점프하는 루프에서 y가 나머지로 나오거나 나누어떨어지는 경우를 찾으면 됨

int solution(int M, int N, int x, int y)
{
	int total = LCM(M, N);
	int index;
	
	for(index = 1; index <= total; ++index)
		if((index - 1) % M + 1 == x) break;
	
	for(int i = index; i <= total; i+= M)
		if((i - 1) % N + 1 == y) return  i;
	
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
