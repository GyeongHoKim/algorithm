/*
2020-12-30
idea: coin count
*/

#include <iostream>
using namespace std;

int factorial(int n)
{
	if(n < 2) return 1;
	return n * factorial(n - 1);
}

int pseudoFactorial(int n)
{
	switch(n) {
	case 0:
		return 1;
		break;
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 6;
		break;
	case 4:
		return 24;
		break;
	case 5:
		return 120;
		break;
	case 6:
		return 720;
		break;
	case 7:
		return 5040;
		break;
	case 8:
		return 40320;
		break;
	case 9:
		return 362880;
		break;
	case 10:
		return 3628800;
		break;
	default:
		return 0;
		break;
	}
}

int permutationWithRepetition(int three, int two, int one)
{
	return pseudoFactorial(three + two + one) / (pseudoFactorial(three) * pseudoFactorial(two) * pseudoFactorial(one));
	//return factorial(three + two + one) / (factorial(three) * factorial(two) * factorial(one));
}

int count(int n)
{
	int three, two, one;
	int countCase = 0;

	for(three = n / 3; three >= 0; --three ) {
		for(two = (n - three * 3) / 2; two >= 0; --two) {
			one = n - three * 3 - two * 2;
			countCase += permutationWithRepetition(three, two, one);
		}
	}

	return countCase;
}

int main()
{
	int C, n;
	cin >> C;

	while(C--) {
		cin >> n;
		cout << count(n) << endl;
	}

	return 0;
}
