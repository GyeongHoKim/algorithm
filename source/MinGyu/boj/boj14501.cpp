#include <iostream>
using namespace std;

bool visit[15] = {false,};
int N,r_sum=0;
int c_day[15];
int c_cost[15];

void back_track(int cnt,int sum) {
  if(cnt >= N) {
    if(r_sum < sum)
      r_sum = sum;
  }
  for(int i=cnt;i<N;i ++){
    if(visit[i]==false){
      if(i + c_day[i] > N){
        visit[i]=true;
        back_track(i+c_day[i],sum);
        visit[i]=false;
      }
      else{
        visit[i]=true;
        back_track(i+c_day[i],sum + c_cost[i]);
        visit[i]=false;
      }
    }
  }
  
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> N;

  for(int i=0;i<N;i++) {
    cin >> c_day[i] >> c_cost[i];
  }

  back_track(0,0);
  cout << r_sum;
}