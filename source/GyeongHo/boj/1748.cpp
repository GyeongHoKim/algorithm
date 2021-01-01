#include <iostream>
#include <string>

using namespace std;

int Len(int N)
{
	string str;
	str = to_string(N);
	return str.length();
}

int powerOfTen(int n)
{
	int tmp = 1;
	for(int i = 0; i < n; ++i)
		tmp *= 10;
	return tmp;
}

int solution(int N)
{
	int len = Len(N);
	int sum = 0;

	for(int i = 0;  i < len; ++i)
		sum += i * powerOfTen(i - 1);
	sum *= 9;

	return sum + (N - powerOfTen(len - 1) + 1) * len;
}

int main()
{
	int N;
	cin >> N;

	cout << solution(N);

	return 0;
}
