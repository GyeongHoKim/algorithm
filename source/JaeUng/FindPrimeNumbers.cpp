#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkP[10000000]; // Prime number
bool checkI[10] = { false }; // Index

bool isPrime(int num) // 소수 판정
{
	if (num == 1 || num == 0)
		return false;

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void rec(string checks, const string& numbers, int& answer)
{
	if (checks != "") 
	{
		int checkstoi = stoi(checks);
		if (!checkP[checkstoi] && isPrime(checkstoi))
		{
			checkP[checkstoi] = true;
			answer++;
		}
	}

	for (int i = 0; i < numbers.length(); i++) // 순열 생성
	{
		if (!checkI[i])
		{
			checkI[i] = true;
			rec(checks + numbers[i], numbers, answer);
			checkI[i] = false;
		}
	}

}


int solution(string numbers)
{
	int answer = 0;
	rec("", numbers, answer);
	return answer;
}