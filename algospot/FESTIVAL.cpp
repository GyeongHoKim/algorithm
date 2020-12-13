#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	int C,N,L;
	cin >> C;
	while(C--)
	{
		cin >> N >> L;
		vector<int> cost(N);
		for(int i = 0; i < N; i++)
			cin >> cost[i];
		
		double min = 100.0;
		double temp;
		vector<int>::iterator iter1 = cost.begin();
		for(; iter1 <= cost.end() - L; iter1++) {
			temp = static_cast<double>(accumulate(iter1, iter1+L-1, 0.0));
			for(
		vector<int>::iterator iter2 = iter1+L-1; iter2 < cost.end(); iter2++) {
				temp += static_cast<double>(*iter2);
				if(min > temp/(iter2-iter1+1))
					min = temp/(iter2-iter1+1);
			}
		}
		
		printf("%.12f\n",min);
		vector<int>().swap(cost);
	}
}