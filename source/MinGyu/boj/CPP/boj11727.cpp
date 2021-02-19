#include <iostream>

#define DIV 10007

long long cache[1001];

long long twoTimesNtile(int n){
  cache[1] = 1;
  cache[2] = 3;

  for(int i=3;i<=n;i++)
    cache[i] = (cache[i-1] + 2*cache[i-2])%DIV;
  
  return cache[n];
}

int main() {
  int N;
  std::cin >> N;
  std::cout << twoTimesNtile(N);
}