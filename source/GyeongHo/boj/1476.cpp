#include <iostream>
using namespace std;

int solution(int E, int S, int M)
{
	for(int i = 1; i < 7981; ++i)
		if((i - 1) % 15 == E && (i - 1) % 28 == S && (i - 1) % 19 == M) return i;
	return -1;
}

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	cout << solution(E, S, M);

	return 0;
}
