#include <iostream>
#include <cstring>

using namespace std;

long long cache[11];
int N;

int addNumberCase(int n) {
  if(n < 1) return 0;
  long long& ref_cache = cache[n];
  if(ref_cache != 0) return ref_cache;

  return ref_cache = (addNumberCase(n-1)+addNumberCase(n-2)+addNumberCase(n-3));

}
int main() {
  int t_case;
  cin >> t_case;

  memset(cache,0,sizeof(cache));

  cache[1] = 1;
  cache[2] = 2;
  cache[3] = 4;

  while(t_case--) {
    cin >> N;
    cout << addNumberCase(N)<<'\n';
  }

  return 0;
}