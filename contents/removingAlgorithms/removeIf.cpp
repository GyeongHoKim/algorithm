#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
    return 30 <= n && n <= 40;
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); i++)
        cout << v[i]; << ' ';
    cout << endl;
    
    vector<int>::iterator iter_end;
    iter_end = remove_if(v.begin(), v.end(), Pred);
    
    cout << "[v.begin(), iter_end) : ";
    for(vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
        cout << *iter << ' ';
    cout << endl;
    
    return 0;
}