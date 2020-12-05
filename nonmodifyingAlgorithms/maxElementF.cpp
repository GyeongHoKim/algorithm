#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point
{
    int x,y;
public:
    explicit Point(int _x = 0, int _y = 0): x(_x), y(_y) {}
    int GetX() const {return x;}
    int GetY() const {return y;}
    void Print() const {cout << '(' << x << ',' << y << ')' << endl;}
};

bool Compare(const Point& left, const Point& right)
{
    if(left.GetX() < right.GetX())
        return true;
    else if(left.GetX() > right.GetX())
        return false;
    else
        return left.GetY() < right.GetY();
}

int main()
{
    vector<Point> v;
    v.push_back(Point(3,2));
    v.push_back(Point(2,5));
    v.push_back(Point(1,5));
    v.push_back(Point(3,3));
    v.push_back(Point(3,2));
    
    vector<Point>::iterator iter;
    iter = max_element(v.begin(), v.end(), Compare);
    cout << "max: "; iter->Print();
    cout << "max: "; *(iter).Print();
    
    return 0;
}