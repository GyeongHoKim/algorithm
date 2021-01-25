#include <iostream>
#include <cstring>
using namespace std;

int cache[100001];

int DP(int N)
{
	int element;
	for(element = 1; element * element <= N; ++element){}
	--element;
	if(cache[N] != -1) return cache[N];
	else return cache[N] = DP(N - element * element) + 1;
}

int main()
{
	int N;
	memset(cache, -1, sizeof(cache));
	cache[0] = 0; cache[1] =1;
	cin >> N;

	cout << DP(N);
	return 0;
}
