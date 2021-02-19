#include <stdio.h>
#include <stdbool.h>

bool visit[8] = {false};
int list[8];
int n,m;

void permutation(int cnt,int num);

int main()
{
  scanf("%d %d",&n,&m);
  permutation(0,0);
  return 0;
}

void permutation(int cnt,int num)
{
  if(cnt == m)
  {
    for(int i = 0; i < m; i++)
    {
      printf("%d ",list[i]);
    }
    printf("\n");
    return ;
  }

  for(int j = 0; j < n; j++)
  {
    if(num>j)
      continue;
    if(visit[j] == false)
    {
      visit[j] = true;
      list[cnt] = j+1;
      permutation(cnt+1,j);
      visit[j] = false;
    }
  }
}