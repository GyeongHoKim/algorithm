#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);

    cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0) << endl;
    cout << inner_product(v1.begin(), v1.end(), v2.begin(), 100) << endl;

    return 0;
}