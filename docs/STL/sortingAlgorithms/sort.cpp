#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Greater(int left, int right)
{
    return left > right;
}

int main()
{
    vector<int> v;

    for(int i = 0; i < 100; ++i)
        v.push_back(rand() % 1000);
    
    cout << "v[before sorting]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    
    sort(v.begin(), v.end());
    cout << "v[sorting by less]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;

    sort(v.begin(), v.end(), Greater);
    cout << "v[sorting by greater]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;

    return 0;
}