#include <iostream>
using namespace std;

int solution(int E, int S, int M)
{
	int e = 0, s = 0, m = 0;
	for(int i = 1; i < 7981; ++i) {
		++e; ++s; ++m;
		if(e > 15) e = 1;
		if(s > 28) s = 1;
		if(m > 19) m = 1;

		if(e == E && s == S && m == M) return i;
	}
	return -1;
}

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	cout << solution(E, S, M);

	return 0;
}
