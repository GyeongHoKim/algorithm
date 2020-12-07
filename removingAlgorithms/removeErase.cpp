#include <iostream>
#include <vector>
#include <algorithm>
usin namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);
    
    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
    
    vector<int>::iterator iter_end;
    iter_end = remove(v.begin(), v.end(), 30);
    
    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
    
    v.erase(ter_end, v.end());
    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
    
    return 0;
}