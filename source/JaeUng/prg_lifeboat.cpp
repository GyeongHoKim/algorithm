#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());
    int start = 0, end = people.size() - 1;

    while(start <= end)
    {
        if(people[start] + people[end] <= limit) // 가장 무거운 사람과 가장 가벼운 사람을 동시에 태울 수 있을 경우
        {
            start += 1;
            end -= 1;
        }
        else // 가장 무거운 사람만 태울 수 있을 경우
        {
            end -= 1;
        }
        answer += 1;
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, limit;
    cin >> n >> limit;
    vector<int> people(n);
    for(int i = 0; i < n; i++)
        cin >> people[i];

    cout << solution(people, limit) << endl;
}