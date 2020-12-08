#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(40);
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(60);

    make_heap(v.begin(), v.end(), greater<int>());
    cout << "v[heap created]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    
    v.push_back(35);
    push_heap(v.begin(), v.end(), greater<int>()); 
    cout << "v[heap added]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;

    sort_heap(v.begin(), v.end(), greater<int>());
    cout << "v[heap sorted] : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;

    return 0;
}