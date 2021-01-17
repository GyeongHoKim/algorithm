#include <iostream>
#include <algorithm>

using namespace std;

int num[14];
bool check[14];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    do {
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> num[i];
            check[i] = i > 6 ? 0 : 1; // 111111 로 시작하는 배열 만들기
        }
        do {
            for (int i = 1; i <= k; i++)
            {
                if (check[i]) { cout << num[i] << ' '; } // 배열 값이 1이라면 num을 출력
            }
            cout << '\n';
        } while (prev_permutation(check + 1, check + 1 + k)); // 1111110...0부터 0...0111111까지의 순열 만들기
        cout << '\n';
    } while(k);
}