#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string cmd;
	int s = 0;
	int m;
	cin >> m;
	while(m--)
	{
		cin >> cmd;
		int x;
		if(cmd == "add")
		{
			cin >> x;
			s |= (1 << x);
		}
		else if(cmd == "remove")
		{
			cin >> x;
			s &= ~(1 << x);
		}
		else if(cmd == "check")
		{
			cin >> x;
			cout << ((s >> x) & 1) << '\n';
		}
		else if(cmd == "toggle")
		{
			cin >> x;
			s ^= (1 << x);
		}
		else if(cmd == "all")
		{
			s = (1 << 21) - 1;
		}
		else if(cmd == "empty")
		{
			s = 0;
		}
	}
}