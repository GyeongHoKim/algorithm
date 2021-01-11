#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int C, L;
string words, answer;
bool visit[15] = {false};

bool chk()
{
	int vowel = 0;
	int consonant = 0;
	for(string::iterator iter = answer.begin(); iter < answer.end(); ++iter) {
		if(*iter == 'a' || *iter == 'e' || *iter == 'i' || *iter == 'o' || *iter == 'u')
			++vowel;
		else
			++consonant;
		if(vowel >= 1 && consonant >= 2) return true;
	}
	return false;
}

void combination(int cnt)
{
	if(cnt == L) {
		if(chk()) {
			for(int i = 0; i < L; ++i)
				cout << answer[i] << ' ';
			cout << "\n";
		}
		return;
	}

	for(int i = 0; i < C; ++i) {
		if(visit[i]) continue;
		visit[i] = true;
		answer.push_back(words[i]);
		combination(cnt + 1);
		visit[i] = false;
		answer.pop_back();
	}
}

int main()
{
	cin >> L >> C;
	for(int i = 0; i < C; ++i) {
		char tmp;
		cin >> tmp;
		words.push_back(tmp);
	}
	
	sort(words.begin(), words.end());
	combination(0);

	return 0;
}
