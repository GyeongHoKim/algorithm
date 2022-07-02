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

    cout << "v : " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    cout << next_permutation(v.begin(), v.end()) << endl;

    return 0;
}