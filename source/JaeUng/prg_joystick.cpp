#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;


int solution(string name)
{
    int answer = 0;
    int shift = name.length() - 1;
    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] == 'A')
        {
            int target = i;
            while(target < name.length() && name[target] == 'A') target += 1; // A가 끝날때 까지 이동
            int left = i == 0 ? 0 : i - 1; // A의 왼쪽 알파벳 개수
            int right = name.length() - target;  // A의 오른쪽 알파벳 개수
            shift = min(shift, left + right + min(left, right)); // 이동해야 할 총횟수
        }
    }
    answer += shift;
    for(auto c : name) answer += min(c - 'A', 'Z' - c + 1);
    return answer;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    string name;
    cin >> name;
    cout << solution(name) << '\n';
}