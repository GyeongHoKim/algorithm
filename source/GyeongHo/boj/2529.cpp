#include <iostream>
#include <string>
#include <vector>
using namespace std;

int k;
string MAX = "0", MIN = "9876543211";
bool visit[10] = {false};
string list ="0123456789";
string ans;
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
		if(!chk()) return;
		if(stoll(ans) > stoll(MAX)) MAX = ans;
		if(stoll(ans) < stoll(MIN)) MIN = ans;
		return;
	}

	for(int i = 0; i < 10; ++i) {
		if(visit[i]) continue;
		visit[i] = true;
		ans.push_back(list[i]);
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
	cout << MIN;

	return 0;
}
