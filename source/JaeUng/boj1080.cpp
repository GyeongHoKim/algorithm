#include <bits/stdc++.h>

using namespace std;

int N, M;
int matrixA[50][50];
int matrixB[50][50];

void toggle(int r, int c)
{
    for(int i = r; i < r + 3; i++)
    {
        for(int j = c; j < c + 3; j++)
        {
            matrixA[i][j] ^= 1;
        }
    }
}

void solve()
{
    int answer = 0;
    for(int i = 0; i < N - 2; i++)
    {
        for(int j = 0; j < M - 2; j++)
        {
            if(matrixA[i][j] != matrixB[i][j])
            {
                toggle(i, j);
                answer += 1;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(matrixA[i][j] != matrixB[i][j])
            {
                answer = -1;
            }
        }
    }
    cout << answer;
}

int main()
{


    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%1d", &matrixA[i][j]);
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%1d", &matrixB[i][j]);
        }
    }
    solve();
}