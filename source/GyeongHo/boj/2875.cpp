#include <iostream>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	cout << min(min(N / 2, M), (N + M - K) / 3) << "\n";
	return 0;
}
