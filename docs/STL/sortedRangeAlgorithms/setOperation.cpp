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
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(60);

    vector<int> v3(10);
    vector<int>::iterator iter_end;

    iter_end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "intersectionSet[v3.begin(), iter_end): ";
    for(vector<int>::iterator iter=v3.begin(); iter != iter_end; ++iter)
        cout << *iter << ' ';
    cout << endl;

    iter_end = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "differenceSet[v3.begin(), iter_end): ";
    for(vector<int>::iterator iter=v3.begin(); iter != iter_end; ++iter)
        cout << *iter << ' ';
    cout << endl;

    iter_end = set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "symmetricDifferenceSet[v3.begin(), iter_end): ";
    for(vector<int>::iterator iter=v3.begin(); iter != iter_end; ++iter)
        cout << *iter << ' ';
    cout << endl;

    return 0;
}