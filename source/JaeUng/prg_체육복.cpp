#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
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
    return n - answer;
}

int main()
{
    int n, s, r;
    cin >> n >> s >> r;

    vector<int> lost(s), reserve(r);
    for(int i = 0; i < s; i++) 
        cin >> lost[i];

    for(int i = 0; i < r; i++) 
        cin >> reserve[i];

    cout << solution(n, lost, reserve);

}