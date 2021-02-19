#include <iostream>
#include <algorithm>

using namespace std;

int waiting_people[1000];

int MinWaitTime(int n){
  int wait_time = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      wait_time += waiting_people[j];
    }
  }
  return wait_time;
}
int main(){
  int N;
  cin >> N;

  for(int i=0;i<N;i++){
    cin >> waiting_people[i];
  }
  sort(waiting_people,waiting_people+N);

  cout << MinWaitTime(N);

  return 0;