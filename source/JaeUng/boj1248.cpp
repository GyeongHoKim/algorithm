#include<iostream>
#include<algorithm>

using namespace std;

int N, A[11];
char S[11][11];
bool solved;

bool check(int start)   // 대각선을 제외한 배열 검사
{
	int prev = 0;
	for (int i = start; i >= 1; i--)
	{
		prev += A[i];
		switch (S[i][start])
		{
		case '0':
			if (prev != 0) return false; 
			break;
		case '-':
			if (prev >= 0) return false;
			break;
		case '+':
			if (prev <= 0) return false;
			break;
		}
	}
	return true;
}

void go(int idx)
{
	if (idx == N + 1)
	{
		for (int i = 1; i <= N; i++)
			printf("%d ", A[i]);
		solved = true;
        return;
	}

	switch (S[idx][idx])    // 대각선 먼저 채우기
	{
	case '0':
		A[idx] = 0;
		go(idx + 1);
		break;
	case '+':
		for (int i = 1; i <= 10; i++)
		{
			A[idx] = i;
			if (check(idx)) go(idx + 1); 
			if (solved) return; 
        }
		break;
	case '-':
		for (int i = -1; i >= -10; i--)
		{
			A[idx] = i;
			if (check(idx)) go(idx + 1);
			if (solved) return; 
		}
		break;
	}
}

int main()
{
	scanf("%d", &N);
    getchar();
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
            scanf("%1c", &S[i][j]);
		}
	}

	go(1);
}