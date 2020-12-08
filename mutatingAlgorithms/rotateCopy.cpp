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
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;

    vector<int> v2(5);
    vector<int>::iterator middle=v.begin()+2;
    vector<int>::iterator iter_end;
    iter_end = rotate_copy(v.begin(), middle, v.end(), v2.begin());
    cout << "v2 : ";
    for(vector<int>::iterator iter=v2.begin(); iter!=iter_end; ++iter)
        cout << *iter << ' ';
    cout <<endl;

    return 0;
}