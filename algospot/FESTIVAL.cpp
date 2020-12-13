#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

double even(vector<int>::iterator iter1, vector<int>::iterator iter2)
{
	/*
	cout << "average among [";
	for(vector<int>::iterator iter = iter1; iter <= iter2; iter++)
		cout << *iter << ',';
	cout << ']' << endl;
	*/
	return static_cast<double>(accumulate(iter1, iter2+1, 0.0)) / static_cast<double>(iter2 - iter1 + 1);
}

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
			for(
		vector<int>::iterator iter2 = iter1+L-1; iter2 < cost.end(); iter2++) {
				temp = even(iter1, iter2);
				if(min > temp)
					min = temp;
			}
		}
		
		printf("%.12f\n",min);
		vector<int>().swap(cost);
	}
}