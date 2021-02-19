#include<iostream>

using namespace std;

bool vist[13] = {false};
int l[13];
int r_l[13];
int n;

void back_track(int cnt,int num) {
  if(cnt == 6) {
    for(int i = 0; i < 6; i++) {
      cout << r_l[i]<<' ';
    }cout << '\n';
  }

  for(int i = num; i < n; i++) {
    if(vist[i] == false)
    {
      vist[i] = true;
      r_l[cnt] = l[i];
      back_track(cnt+1,i);
      vist[i] = false;
    }
  }
}

int main()
{
  while(1) {
    cin >> n;
    if(n==0) break;
    for(int i=0;i<n;i++) {
      cin >> l[i];
    }
    back_track(0,0);
    cout << '\n';
  }
  return 0;
}