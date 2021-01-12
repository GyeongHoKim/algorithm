#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
char a[16];
void go(int index, int cnt, int mo, int ja, string s)
{
	if(cnt == L) {
		if(mo >= 1 && ja >= 2)
			cout << s << "\n";
		return;
	}
	if(index == C) return;
	if(a[index] == 'a' || a[index] == 'e' || a[index] == 'i' || a[index] == 'o' || a[index] == 'u')
		go(index + 1, cnt + 1, mo + 1, ja, s + a[index]);
	else
		go(index + 1, cnt + 1, mo, ja + 1, s + a[index]);
}

int main()
{
	cin >> L >> C;
	for(int i = 0; i < C; ++i)
		cin >> a[i];
	sort(a, a+C);
	go(0, 0, 0, 0, "");
	return 0;
}
