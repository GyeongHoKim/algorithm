#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;


int solution(string name)
{
    int answer = INF;
    int shift = 0;
    for(int i = 0; i < name.length(); i++)
    {
        int cur = i;
        if(name[i] == 'A') //A가 나올 경우
        {
            while(i < name.length() && name[i] == 'A') i += 1; // A가 끝날때 까지 인덱스 이동
            if(i == name.length()) break; //끝까지 A일경우 그대로 종료
            
            int r = i - cur + (cur == 0 ? 0 : 1); //오른쪽으로 갈 경우
            int l = (int)name.length() - r; //왼쪽으로 갈 경우
            answer = min(answer, shift + l); //왼쪽으로 가는 경우 문자열 순회가 끝남
            shift += r; //오른쪽으로 갈 경우 계속 탐색해야함
        }
        else if(i != 0)
        {
            shift += 1;
        }
    }
    answer = min(shift, answer); // 오른쪽으로만 계속 간 경우와 왼쪽으로 한번이라도 간 경우

    for(auto c : name) answer += min(c - 'A', 'Z' - c + 1);
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    while(1)
    {
        cin >> name;
        cout << solution(name) << '\n';
    }
}