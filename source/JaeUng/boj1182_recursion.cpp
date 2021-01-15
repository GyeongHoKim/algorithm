#include<iostream>

using namespace std;

int seq[21];
int ans;
int n, s;

void go(int start, int prev, int num)
{
	if (start == n) return;

	go(start + 1, prev, num);

	prev += seq[start];
	num++;
	if (num > 0 && prev == s) { ans++; }
	go(start + 1, prev, num);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}
	go(0, 0, 0);
	cout << ans;

}