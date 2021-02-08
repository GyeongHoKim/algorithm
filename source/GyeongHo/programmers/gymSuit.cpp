#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end()); sort(reserve.begin(), reserve.end());

    for (vector<int>::size_type i = 0; i < reserve.size(); ++i) {
        vector<int>::iterator justOneLeft = find(lost.begin(), lost.end(), reserve[i]);
        if(justOneLeft != lost.end()) {
            lost.erase(justOneLeft);
            reserve.erase(reserve.begin() + i);
            --i;
        }
    }

    int answer = n - lost.size();

    for (vector<int>::size_type i = 0; i < lost.size(); ++i) {
        vector<int>::iterator prev = find(reserve.begin(), reserve.end(), lost[i] - 1);
        vector<int>::iterator next = find(reserve.begin(), reserve.end(), lost[i] + 1);
        if (prev != reserve.end()) {
            reserve.erase(prev);
            ++answer;
        }
        else if(next != reserve.end()) {
            reserve.erase(next);
            ++answer;
        }
    }

    return answer;
}