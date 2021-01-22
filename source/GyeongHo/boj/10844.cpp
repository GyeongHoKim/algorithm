#include <iostream>
using namespace std;

int cache[101];

int DP(int n)
{
	if(cache[n] != 0) return cache[n];
	return cache[n] = (DP(n - 1) * 2 - 1) % 1000000000;
}

int main()
{
	int n;
	cin >> n;
	cache[1] = 9; cache[2] = 17;

	cout <<DP(n);
	return 0;
}
