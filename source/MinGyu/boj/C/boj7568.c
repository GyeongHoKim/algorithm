#include <stdio.h>
#include <string.h>
int people[51][2];

int main()
{
  int n,h,w,count=0;
  scanf("%d",&n);

  memset(people,0,sizeof(int)*51*2);
  for(int i=0;i<n;i++){
    scanf("%d %d",&w,&h);
    people[i][0]=w;
    people[i][1]=h;
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(people[i][0]<people[j][0]&&people[i][1]<people[j][1]) count+=1;
    }
    printf("%d ",count+1);
    count = 0;
  }
}