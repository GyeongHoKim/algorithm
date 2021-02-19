#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
long long start_time[100000], end_time[100000];

int Solved(int n){
  vector<pair<long long, long long>>order;

  for(int i=0;i<n;i++){
    order.push_back(make_pair(end_time[i],start_time[i]));
  }
  sort(order.begin(),order.end());

  long long earliest = 0;
  int count = 0;
  
  for(int i=0;i<order.size();i++){
    long long meeting_begin = order[i].second, meeting_end = order[i].first;

    if(earliest <= meeting_begin){
      earliest = meeting_end;
      count ++;
    }
  }
  return count;
}

int main(){
  int N;
  cin >> N;

  for(int i=0;i<N;i++){
    cin >> start_time[i] >> end_time[i];
  }
  
  cout << Solved(N);

  return 0;
}