#include <iostream>
#include <cstring>

using namespace std;
int cache[1000007];

int makeOneCount(int n) {
  if(n<=1) return 0;
  int& ref_cache = cache[n];
  if(ref_cache != -1) return ref_cache;

  ref_cache = makeOneCount(n-1) + 1;

  if(n%3 == 0) 
    ref_cache = min(ref_cache,makeOneCount(n/3) + 1);

  if(n%2 == 0)
    ref_cache = min(ref_cache,makeOneCount(n/2) + 1);
  
  return ref_cache;
}
int main() {
  int N;
  cin >> N;

  memset(cache,-1,sizeof(int)*(N+1));

  cache[1] = 0;
  cache[2] = 1;
  cache[3] = 1;

  cout << makeOneCount(N);

  return 0;
}