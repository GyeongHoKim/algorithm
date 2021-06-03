#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int A[100000];
int B[100000];

int bs(int num)
{
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[mid] == num)
            return 1;
        else if (A[mid] > num)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A, A + n);
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> B[i];

    for (int i = 0; i < m; ++i)
        cout << bs(B[i]) << "\n";

    return 0;
}