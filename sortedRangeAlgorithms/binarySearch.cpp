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
    
    if(binary_search(v.begin(), v.end(), 20))
        cout << "element 20 exists" << endl;
    else
        cout << "element 20 does not exist" << endl;
        
    return 0;
}