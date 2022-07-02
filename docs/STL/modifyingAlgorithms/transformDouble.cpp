#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Plus(int left, int right)
{
    return left+right;
}

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    
    vector<int> v3(5);
    
    vector<int>::iterator iter_end;
    iter_end = transform(v1.begin(), v1.end(), v2.begin(), b3.begin, Plus);
    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << ' ';
    cout << endl;
    cout << "v2 : ";
    for(vector<int>::size_type i = 0; i < v2.size(); ++i)
        cout << v2[i] << ' ';
    cout << endl;
    cout << "v3 : ";
    for(vector<int>::size_type i = 0; i < v3.size(); ++i)
        cout << v3[i] << ' ';
    cout << endl;
    return 0;
}