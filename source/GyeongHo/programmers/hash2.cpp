#include <string>
#include <map>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> hashTable;
    for (auto number : phone_book) {
        string tmp = "";
        for (int i = 0; i < number.length(); ++i) {
            tmp += number[i];
            hashTable[tmp]++;
        }
    }
    for (auto number : phone_book) {
        if (hashTable[number] > 1) {
            return false;
        }
    }
    return true;
}