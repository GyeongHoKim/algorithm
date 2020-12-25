#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    vector<int> numbersV;
    vector<int> answers;
    
    //여기서부터 소수리스트 만들기, 소수면 true 아니면 false
    vector<bool> prime(100000000,true);
    prime[0] = prime[1] = false;
    for(int i = 2; i < 100000000; ++i)
        if(prime[i])
            for(int j = i; j < 100000000; j *= j)
                prime[j] = false;
    
    //여기서부터 종이조각으로 순열만들어서 모든 경우의 수 리스트 만들기
    for(string::size_type i = 0; i < numbers.size(); ++i)
        numbersV.push_back(numbers[i] - '0');
    
    sort(numbersV.begin(), numbersV.end());
    do {
        for(vector<int>::size_type i = 0; i < numbersV.size(); ++i) {
            int temp = 0;
            for(vector<int>::size_type j = 0; j < i; ++j) {
                temp += (temp * 10) + numbersV[j];
                answers.push_back(temp);
            }
        }
    } while(next_permutation(numbersV.begin(), numbersV.end()));
    
    sort(answers.begin(),answers.end());
    answers.erase(unique(answers.begin(), answers.end()), answers.end());
    
    for(vector<int>::size_type i = 0; i < answers.size(); ++i)
        if(prime[answers[i]]) answer += 1;
    
    return answer;
}