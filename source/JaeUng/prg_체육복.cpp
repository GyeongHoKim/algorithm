#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector<bool> check(n+1);
    
    for(auto l : lost)
    {
        for(auto r : reserve)
        {
            if(l == r)
            {
                check[l] = true;
                answer += 1;
            }
        }
    }//여벌 == 체육복
    
    for(auto l : lost)
    {
        for(auto r : reserve)
        {
            if(!check[r] && !check[l] && abs(r-l) == 1)
            {
                answer += 1;
                check[r] = true;
                break;
            }
        }
    }
    return answer;
}