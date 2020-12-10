#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

template<typename T>
struct Plus
{
    T operator() (const T& left, const T& right)
    {
        return left+right;
    }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    cout << "v: ";
    for(vector<int>::size_type i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    
    cout << accumulate(v.begin(), v.end(), 0, Plus<int>()) << endl;
    cout << accumulate(v.begin(), v.end(), 0, plus<int>()) << endl;
    cout << accumulate(v.begin(), v.end(), 1, multiplies<int>()) << endl;
    
    return 0;
}