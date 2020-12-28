/*
   2020-12-28
   김경호
   백준 일곱난장이
아홉 명의 키가 주어지고 그 중 7명의 합이 100이 되는 아무경우를 오름차순으로 출력
아이디어:루프문에서 합이 100이 될 때 스탑하고 출력
 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<int>& height)
{
	int sum;
	sort(height.begin(), height.end());

	do {
		sum = 0;
		for(int i = 0; i < 7; ++i)
			sum += height[i];
		if(sum == 100) {
			height.erase(height.begin() + 6, height.end());
			sort(height.begin(), height.end());
			return;
		}
	} while(next_permutation(height.begin(), height.end()));
	return;
}

int main()
{
	vector<int> height(9);
	for(int i = 0; i < 9; ++i)
		cin >> height[i];

	solution(height);
	for(int i = 0; i < 7; ++i)
		cout << height[i] << endl;

	return 0;
}
