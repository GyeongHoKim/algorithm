#include <iostream>
using namespace std;

int hansu(int N)
{
	int count = 99;
	if(N < 100) return N;
	else if(N < 111) return count;
	else{
		for(int i = 111; i < N + 1; ++i)
			if(((i % 100) - (i % 10)) / 10 - (i % 10) == (i - (i % 100)) / 100 - ((i % 100) - (i % 10)) / 10)
				count++;
		return count;
	}
}

int main()
{
	int N;

	cin >> N;

	cout << hansu(N);

	return 0;
}
