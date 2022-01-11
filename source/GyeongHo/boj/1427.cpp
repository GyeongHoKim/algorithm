#include <bits/stdc++.h>
using namespace std;

int partition(int* array, int start, int end)
{
    int pivot = array[start];
    int left = start + 1;
    int right = end;
    int tmp;

    while (left <= right) {
        while (left <= end && array[left] >= pivot)
            left++;
        while (right > start && array[right] <= pivot)
            right--;
        if (left < right) {
            tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
        }
    }
    array[start] = array[right];
    array[right] = pivot;
    return right;
}

void quick_sort(int* array, int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(array, start, end);
    quick_sort(array, start, pivot - 1);
    quick_sort(array, pivot + 1, end);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int arr[10];
    string str;
    int n = 0;
    cin >> str;
    for (char i : str)
        arr[n++] = i - '0';
    
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
        cout << arr[i];
    
    return 0;
}