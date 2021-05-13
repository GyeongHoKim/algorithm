#include <string>
#include <map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> hashTable;
    for (auto c : completion) {
        hashTable[c] += 1;
    }
    for (auto p : participant) {
        hashTable[p] -= 1;
        if (hashTable[p] < 0)
            return p;
    }
    return "";
}