#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int W[11][11];

void solve()
{
    int ans = INT_MAX;
    int perm[20];
    for (int i = 1; i <= N; i++)
    {
        perm[i] = i;
    }   

    do {
        int sum = 0;
        for (int i = 1; i < N; i++)
        {
            if (W[perm[i]][perm[i+1]])
                sum += W[perm[i]][perm[i+1]];
            else
            {    
                sum = 0;
                break;
            }
        }
        if (sum && W[perm[N]][perm[1]])
        { 
            sum += W[perm[N]][perm[1]];
            ans = min(ans, sum);
        }
    } while (next_permutation(perm + 1, perm + 1 + N));
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> W[i][j];
        }
    }
    solve();
}