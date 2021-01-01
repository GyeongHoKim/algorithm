#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int MAX = 1000007;
bool broken[10];
int N, M;

bool possible(int k)
{
	if(k == 0)
		return broken[0] ? false : true;
	while(k) {
		if(broken[k % 10] == true)
			return false;
		k /= 10;
	}
	return true;
}

int find()
{
	int ret = abs(N - 100);
	int tmp;
	int inf = N * 2 - 100;
	if(inf < 100) inf = 100;
	if(M == 10) return ret;

	for(int i = N; i <= inf; ++i) {
		tmp = to_string(i).length() + abs(i - N);
		if(possible(i)) {
			ret = min(tmp, ret);
			break;
		}
	}

	for(int i = N; i >= 0; --i) {
		tmp = to_string(i).length() +abs(i - N);
		if(possible(i)) {
			ret = min(tmp, ret);
			break;
		}
	}

	return ret;
}

int main()
{
	int tmp;
	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		cin >> tmp;
		broken[tmp] = true;
	}

	cout << find() << endl;
	return 0;
}
