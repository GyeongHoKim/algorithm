#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int k;
char s[10];

vector<int> minNum, maxNum;
bool check[10];
bool solved;

bool use(int i, int idx, vector<int>& num) //들어갈 수 있는 숫자인지 검사
{     
    return !check[i] && 
    ((s[idx] == '<' && num[idx] < i) || (s[idx] == '>' && num[idx] > i));
}

void findMin(int idx)
{
    if (idx == k)
    {
        solved = true;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (use(i, idx, minNum))
        {
            minNum.push_back(i); check[i] = true;
            findMin(idx + 1);
            if (solved) return; 
            minNum.pop_back(); check[i] = false;
        }
    }
}

void findMax(int idx)
{
    if (idx == k) 
    {
        solved = true;
        return;
    }
    for (int i = 9; i >= 0; i--)
    {
        if (use(i, idx, maxNum))
        {
            maxNum.push_back(i); check[i] = true;
            findMax(idx + 1);
            if (solved) return; 
            maxNum.pop_back(); check[i] = false;
        }
    }
}

void solve()
{   
    for (int i = 0; i <= 9; i++) //첫자리에 들어갈 숫자 넣고 가장 작은 수 구하기
    {
        minNum.push_back(i); check[i] = true;
        findMin(0);
        if (solved) break; 
        minNum.pop_back(); check[i] = false;
    }

    solved = false;
    memset(check, false, sizeof(check));//초기화
    
    for (int i = 9; i >= 0; i--) //첫자리에 들어갈 숫자 넣고 가장 큰 수 구하기
    {
        maxNum.push_back(i); check[i] = true;
        findMax(0);
        if (solved) break;
        maxNum.pop_back(); check[i] = false;
    }

    for (const auto& n: maxNum) cout << n; cout << '\n';
    for (const auto& n: minNum) cout << n; //출력
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++) cin >> s[i];
    solve();
}