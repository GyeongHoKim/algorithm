/*
날짜 : 2020.12.25.금
아이디어 : brown과 yellow를 합한 것을 x * y로 분해(x > y)하여 (x + y) * 2 - 4가 brown보다 같거나 작아야 함.
        yellow를 감싸려면 y는 최소 3
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int x = 2005000, y =3;
    int totalBlock = brown + yellow;
    vector<int> answer;
    
    while(x > y) {
        if(totalBlock % y == 0) {
            x = totalBlock / y;
            if((x + y) * 2 - 4 <= brown) {
                answer.push_back(x);
                answer.push_back(y);
                return answer;
            }
        }
        ++y;
    }
    
    return answer;
}