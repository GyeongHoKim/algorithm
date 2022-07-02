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
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter;
    iter = adjacent_find(v.begin(), v.end());
    //같은 원소가 없다면 구간의 끝을 표시하는 반복자를 반환한다

    if(iter != v.end())
        cout << *iter << endl;

    for(; iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}