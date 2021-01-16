#include <iostream>
#include <string>
#include <vector>
using namespace std;

int k, MAX = -1, MIN = 987654321;
bool visit[10] = {false};
vector<int> ans;
string compare;

bool chk()
{
	for(int i = 0; i < k; ++i) {
		if(compare[i] == '>' && ans[i] < ans[i+1])
			return false;
		if(compare[i] == '<' && ans[i] > ans[i+1])
			return false;
	}
	return true;
}

void permutation(int cnt)
{
	if(cnt == k + 1) {
		int sum = 0;
		if(!chk()) return;
		for(int i = 0; i <= k; ++i){
			sum *= 10;
			sum += ans[i];
		}
		if(MAX < sum) MAX = sum;
		if(MIN > sum) MIN = sum;
		return;
	}

	for(int i = 0; i < 10; ++i) {
		if(visit[i]) continue;
		visit[i] = true;
		ans.push_back(i);
		permutation(cnt + 1);
		visit[i] = false;
		ans.pop_back();
	}
}

int main()
{
	cin >> k;
	for(int i = 0; i < k; ++i) {
		char tmp;
		cin >> tmp;
		compare.push_back(tmp);
	}

	permutation(0);
	
	cout << MAX << "\n";
	if(compare[0] == '<')
		cout << '0';
	cout << MIN;

	return 0;
}
