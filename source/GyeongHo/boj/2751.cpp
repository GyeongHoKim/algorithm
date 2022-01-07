#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int sorted[1000000];

void merge(int* array, int m, int middle, int n)
{
    int t, i = m, j = middle + 1, k = m;
    while (i <= middle && j <= n) {
        if (array[i] < array[j])
            sorted[k++] = array[i++];
        else
            sorted[k++] = array[j++];
    }
    if (middle < i)
        while (j <= n)
            sorted[k++] = array[j++];
    if (n < j)
        while (i <= middle)
            sorted[k++] = array[i++];
    for (t = m; t <= n; ++t)
        array[t] = sorted[t];
}

void mergeSort(int* array, int m, int n)
{
    if (m >= n)
        return;
    int middle = (m + n) / 2;
    mergeSort(array, m, middle);
    mergeSort(array, middle + 1, n);
    merge(array, m, middle, n);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << "\n";

    return 0;
}