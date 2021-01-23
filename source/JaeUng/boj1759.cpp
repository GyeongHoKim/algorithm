#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
char alphabet[16];
vector<char> password;

bool isVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

void solve(int consonant, int vowel, int idx)
{
    if (password.size() == L && consonant >= 2 && vowel >= 1) //유효한 암호일 경우
    {
        for (const auto& c : password) cout << c; 
        cout << '\n';
        return;
    }
    if (idx == C) // 암호 완성 실패
        return;
    
    password.push_back(alphabet[idx]); // 알파벳을 선택 한 경우
    isVowel(alphabet[idx]) ? solve(consonant, vowel + 1, idx + 1) : solve(consonant + 1, vowel, idx + 1);
    password.pop_back(); // 알파벳을 선택하지 않은 경우
    solve(consonant, vowel, idx + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> alphabet[i];
    
    sort(alphabet, alphabet + C);
    solve(0, 0, 0);
}