#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int C, N;
	cin >> C;
	while(C--) {
		cin >> N;
		int sum = 0, count;
		float average;
		vector<int> grade(N);
		for(int i = 0; i < N; i++) {
			cin >> grade[i];
			sum += grade[i];
		}
		average = static_cast<float>(sum / N);
		sort(grade.begin(), grade.end(), greater<int>());
		
		for(count = 0; static_cast<float>(grade[count]) > average; count++);
		printf("%.3f%%\n",static_cast<float>(count) / N * 100);
	}
}