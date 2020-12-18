#include <iostream>
using namespace std;


bool areFriends[10][10];

int count(bool* studentList, int n)
{
	int cases = 0;
	int index = -1;
	for(int i = 0; i < n; ++i) {
		if(!studentList[i]) {
			index = i;
			break;
		}
	}
	
	if(index == -1) return ++cases;
	
	for(int j = index + 1; j < n; ++j) {
		if(areFriends[index][j] && !studentList[j]) {
			studentList[index] = true;
			studentList[j] = true;
			cases += count(studentList, n);
			studentList[index] = false;
			studentList[j] = false;
		}
	}
	
	return cases;
}

int main()
{
	int C, n, m;
	cin >> C;
	
	while(C--) {
		cin >> n >> m;
		
		for(int i = 0; i < 10; ++i)
			for(int j = 0; j < 10; ++j)
				areFriends[i][j] = false;
		
		bool* studentList = new bool[n];
		for(int i = 0; i < n; ++i) studentList[i] = false;
		
		while(m--) {
			int i, j;
			cin >> i >> j;
			areFriends[i][j] = true;
			areFriends[j][i] = true;
		}
		
		cout << count(studentList, n) << endl;
		
		delete[] studentList;
	}
	
	return 0;
}