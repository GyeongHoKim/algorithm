#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //vector<int>::iterator iter_lower, iter_upper;
    pair<vector<int>::iterator, vector<int>::iterator> iter_pair;

    iter_pair = equal_range(v.begin(), v.end(), 30);

    cout << "sequence of element 30 [iter_lower, iter_upper): ";
    for(vector<int>::iterator iter = iter_pair.first; iter != iter_pair.second; ++iter)
        cout << *iter << ' ';
    cout << endl;

    return 0;
}