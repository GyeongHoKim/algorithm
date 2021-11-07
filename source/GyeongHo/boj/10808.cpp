#include <bits/stdc++.h>
using namespace std;

string words;

int main()
{
	int arr[26];
	cin >> words;

	fill(arr, arr + 26, 0);

	for (char word : words) {
		int idx = word - 'a';
		++arr[idx];
	}

	for (int idx = 0; idx < 26; ++idx)
		cout << arr[idx] << ' ';

	return 0;
}

