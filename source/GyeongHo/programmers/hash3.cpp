#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> hashTable;
    for (auto& cloth : clothes) {
        hashTable[cloth[1]] += 1;
    }
    
    for (auto& element : hashTable) {
        answer *= element.second + 1;
    }
    return answer - 1;
}