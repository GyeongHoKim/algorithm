#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> supoOne = {1, 2, 3, 4, 5};
vector<int> supoTwo = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> supoThree = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);
    int maxScore;
    
    for(vector<int>::size_type i = 0; i < answers.size(); ++i) {
        if(answers[i] == supoOne[i % supoOne.size()]) score[0] += 1;
        if(answers[i] == supoTwo[i % supoTwo.size()]) score[1] += 1;
        if(answers[i] == supoThree[i % supoThree.size()]) score[2] += 1;
    }
    
    maxScore = *max_element(score.begin(), score.end());
    
    for(int i = 0; i < 3; ++i)
        if(score[i] == maxScore)
            answer.push_back(i+1);
    
    return answer;
}