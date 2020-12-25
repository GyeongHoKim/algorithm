# 문제 설명

한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

**제한사항**
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

**입출력 예**
| numbers | return |
| :---: | :---: |
| 17 | 3 |
| 011 | 2 |

**입출력 예 설명**
예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.

# 나의 풀이
제 풀이가 아래와 같습니다.

``` c++
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
```

왜 틀렸을까요????