#include <stdio.h>
#include <stdlib.h>

int broken[10]={0,0,0,0,0,0,0,0,0,0};

int check(int a);
int find(int n);
int Min(int a,int b){
  if(a<b)
    return a;
  return b;
}

int main()
{
  int n,m,result;
  scanf("%d",&n);
  scanf("%d",&m);

  while(m--){
    int num;
    scanf("%d",&num);
    broken[num] = 1;
  }

  result = find(n);
  printf("%d",result);
}

int check(int a)
{
  int click=0;
  if(a == 0){
    if(broken[0]==1)
      return 0;
    else 
      return 1;
  }
  while(a){
    if(broken[a%10] == 1)
      return 0;
    a /=10;
    click +=1;
  }
  return click;
}

int find(int n)
{
  int click =0,min=0,result=abs(n-100);
  for(int i=0;i<1000000;i++){
    click = check(i);
    if(click){
      min = abs(i-n)+click;
      result = Min(result,min);
    }    
  }
  return result;
}