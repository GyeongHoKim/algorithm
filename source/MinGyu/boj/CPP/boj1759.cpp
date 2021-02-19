#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L,C;
bool visit[13] = {false, };
char p[13];
char r_p[13];

void back_track(int cnt,int num,int ja,int mo) {
  if(cnt == L) {
    if(ja >=2 && mo>=1){
      for(int i=0;i<L;i++)
      cout << r_p[i];
    cout << '\n';
    }
  } 

  for(int i=num;i<C;i++) {
    if(visit[i]==false) {
      visit[i] = true;
      r_p[cnt] = p[i];

      if(r_p[cnt]=='a'||r_p[cnt]=='e'||r_p[cnt]=='i'||r_p[cnt]=='o'||r_p[cnt]=='u')
        back_track(cnt+1,i,ja,mo+1);
      else 
        back_track(cnt+1,i,ja+1,mo);

      visit[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> L >> C;

  for(int i=0;i<C;i++)
    cin >> p[i];
  
  sort(p,p+C);

  back_track(0,0,0,0);

  return 0;

}