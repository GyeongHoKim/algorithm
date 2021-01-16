#include <iostream>
#include <string>

using namespace std;
int n, num, bit=0;
string command;

int main() {
    
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  cin >> n;
  while(n--)
  {
    command.clear();
    cin >> command;
    if(command== "add")
    {
      cin >> num;
      bit |= (1<<num);
    }
    else if(command== "remove")
    {
      cin >> num;
      bit &= ~(1<<num);
    }
    else if(command== "check")
    {
      cin >> num;
      if(bit&(1<<num)) cout << 1 <<'\n';
      else cout << 0 << '\n';
    }
    else if(command== "toggle")
    {
      cin >> num;
      bit ^= (1<<num);
    }
    else if(command== "all")
    {
      bit = (1<<21)-1;
    }
    else if(command== "empty")
    {
      bit = 0;
    }
  }
  return 0;
}