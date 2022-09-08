#include <bits/stdc++.h>
using namespace std;

class segmentTree {
    int* st;
    int* arr;
    int n;
public:
    segmentTree(int* _arr, int _n) {
        arr = _arr;
        n = _n;
        st = new int[n * 4];
        initSegmentTree(1, 0, n - 1);
    }

    int initSegmentTree(int node, int start, int end) {
        if (start == end)
            return st[node] = arr[start];
        int mid = (start + end) / 2;
        return st[node] = max(initSegmentTree(node * 2, start, mid), initSegmentTree(node * 2 + 1, mid + 1, end));
    }

    int find(int fStart, int fEnd, int nStart, int nEnd, int node) {
        if (fEnd < nStart  || fStart > nEnd)
            return -1;
        if (fStart <= nStart && nEnd <= fEnd)
            return st[node];
        int mid = (nStart + nEnd) / 2;
        return max(find(fStart, fEnd, nStart, mid, node * 2), find(fStart, fEnd, mid + 1, nEnd, node * 2 + 1));
    }
};

int arr[1000000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    segmentTree segTree = segmentTree(arr, n);

    int accSum, p1 = 0, p2 = 2 * m - 2;
    while (p2 < n)
        cout << segTree.find(p1++, p2++, 0, n - 1, 1) << ' ';

    return 0;
}