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
        if(people[start] + people[end] <= limit)
        {
            start += 1;
            end -= 1;
        }
        else
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