#include <bits/stdc++.h>
using namespace std;

int visited[200001];
int dir[3] = {-1, 1, 2};
int k, n;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i <= 200000; ++i) visited[i] = INT_MAX;
    cin >> n >> k;
    queue<int> q;
    
    q.push(n);
    visited[n] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < 3; ++i) {
            int next = cur + dir[i];
            if (i == 2)
                next = cur * 2;
            if (next < 0 || next >= 200000 || visited[next] < visited[cur] + 1)
                continue;
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
    cout << visited[k];
    return 0;
}