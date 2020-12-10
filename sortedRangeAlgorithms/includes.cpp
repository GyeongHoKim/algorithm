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
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(40);

    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(60);

    if(includes(v1.begin(), v1.end(), v2.begin(), v2.end()))
        cout << "v2 is subset of v1" << endl;
    else
        cout <<"v2 is not subset of v1" << endl;

    if(includes(v1.begin(), v1.end(),v3.begin(), v3.end()))
        cout << "v3 is subset of v1" << endl;
    else
        cout << "v3 is not subset of v3" << endl;
    
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    if(includes(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()))
        cout << "greater sorted sequence: v2 is subset of v1" << endl;
    
    return 0;
}