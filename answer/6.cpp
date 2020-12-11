#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
	vector<int> v1, v2, v3;
	v1.push_back(50);
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(80);
	v1.push_back(60);
	
	v2.push_back(20);
	v2.push_back(70);
	v2.push_back(40);
	
	cout << "v1: ";
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "v2: ";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "v3: ";
	copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.begin()));
	cout << endl;
	
	cout << "v1: ";
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "v2: ";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "v3: ";
	copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	return 0;
}