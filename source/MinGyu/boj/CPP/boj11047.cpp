#include <iostream>

using namespace std;

int wallet[10];

int CountingCoin(int n,int k){
  int pay_money = 0,count_coin = 0;

  for(int i=0;i<n;i++){
    if( k - pay_money >= wallet[i] ){
      while(pay_money < k){
        pay_money += wallet[i];
        count_coin++;
      }
      if(pay_money == k) break;
      else{ pay_money -= wallet[i]; count_coin--;}
    }
  }

  return count_coin;
}
int main(){
  int N,K;
  cin >> N >> K;

  for(int i=N-1;i>=0;i--){
    cin >> wallet[i];
  }

  cout << CountingCoin(N, K);

  return 0;
}
