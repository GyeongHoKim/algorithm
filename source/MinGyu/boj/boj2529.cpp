#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visit[10] = {false, };
char c[10];
char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
int n;
vector<string>all;

void back_track(int cnt,int M,string a) {

  if(cnt == n+1) {
    all.push_back(a);
  }

  for(int i=0;i<10;i++) {
    if(visit[i]==false) {
      if(cnt > 0 && c[cnt]=='<') {
        if(M > i) continue;
      }
      if(cnt > 0 && c[cnt]=='>') {
        if(M < i) continue;
      }
      visit[i] = true;
      back_track(cnt+1,i,a + num[i]);
      visit[i] = false;
    }
  }
}

int main() {
  cin >> n;

  for(int i=1;i<=n;i++)
    cin >> c[i];

  back_track(0,0,"");

  cout << all.back() <<'\n';
  cout << all.front();

}