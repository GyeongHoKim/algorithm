#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int left, int right
{
    return 3 < right-left;
}
int main()
{
    vector<int> v;
    v.push_back(40);
    v.push_back(46);
    v.push_back(12);
    v.push_back(80);
    v.push_back(10);
    v.push_back(47);
    v.push_back(30);
    v.push_back(55);
    v.push_back(90);
    v.push_back(53);
    
    cout << "[v 원본]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    
    sort(v.begin(), v.end(), 32, Pred);
    cout << "[v: sorting]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    
    if(binary_search(v.begin(), v.end(), 32, Pred))
        cout << "element 32 exists" << endl;
    else
        cout << "element 32 does not exist" << endl;
    
    if(binary_search(v.begin(), v.end(), 32, Pred))
        cout << "element 35 exists" << endl;
    else
        cout << "element 35 does not exist" << endl;
    
    return 0;
}