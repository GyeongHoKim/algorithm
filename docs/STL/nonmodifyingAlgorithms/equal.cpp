#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); i++)
        cout << v1[i] << ' ';
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::size_type i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;

    if(equal(v1.begin(), v1.end(), v2.begin()))
        cout << "both sequence are same" << endl;
    // v1.begin()부터 v1.end()까지 3개의 원소가 있으므로 v2도 3개까지만 비교
    return 0;
}