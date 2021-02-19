#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;
int score[20][20];
vector<int> start;
vector<int> link;
int min_score = 999999;
void insert_member(int bit){
  start.clear();
  link.clear();

  for(int i=0;i<N;i++){
    if((bit&(1<<i))) start.push_back(i);
    else link.push_back(i);
  }
}
int score_member(void);

int main() {

  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> score[i][j];
    }
  }

  for(int i=0;i<(1<<N);i++){
    int start_sum=0,link_sum=0;

    insert_member(i);

    if(start.size()!=link.size()) continue;
    
    for(int j=0;j<N/2;j++){ 
      for(int k=0;k<N/2;k++){
        if(j==k)continue;
        start_sum += score[start[j]][start[k]];
        link_sum += score[link[j]][link[k]];
      }
    }

    if(abs(start_sum-link_sum)<min_score)
      min_score = abs(start_sum - link_sum);
    
  }
  cout << min_score;
}
