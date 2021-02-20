#include <bits/stdc++.h>

using namespace std;

void switching(vector<int>& state, int idx)
{
    for(int i = idx - 1; i <= idx + 1; i++)
    {
        if(i < state.size())
            state[i] = !state[i];
    }
}

int solve(vector<int> state, vector<int>& target, int ans)
{
    int size = state.size();
    for(int i = 0; i < size - 1; i++)
    {
        if(state[i] != target[i])
        {
            ans += 1;
            switching(state, i + 1);
        }
    }
    if(state[size - 1] == target[size - 1])
        return ans;
    else 
        return -1;
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> state(N);
    vector<int> target(N);

    for(int i = 0; i < N; i++)
        scanf("%1d", &state[i]);
    for(int i = 0; i < N; i++)
        scanf("%1d", &target[i]);

    int ans1 = solve(state, target, 0); // 첫 번째 스위치를 안누른 상태
    state[0] = !state[0], state[1] = !state[1]; 
    int ans2 = solve(state, target, 1); // 첫 번째 스위치를 누른 상태

    if(ans1 == -1 && ans2 == -1) cout << -1;
    else if(ans1 != -1) cout << ans1;
    else if(ans2 != -1) cout << ans2;
    else cout << min(ans1, ans2);

}