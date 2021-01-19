#include <iostream>
#include <cstring>
using namespace std;

int cache[1001];

int set(int n)
{
	int& ret = cache[n];
	if(ret != -1) return ret;
	else return ret = (set(n - 1) + set(n - 2)) % 10007;
}

int main()
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	cache[1] = 1;
	cache[2] = 2;

	cout << set(n);
	return 0;
}
