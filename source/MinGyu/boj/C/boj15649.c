#include <stdio.h>
#include <stdbool.h>

bool vist[8] = {false};
int list[8];
int n,m;

void permutation( int cnt);

int main()
{
  scanf("%d %d",&n,&m);
  permutation(0);
  return 0;
}

void permutation(int cnt)
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
    if(vist[j] == false)
    {
      vist[j] = true;
      list[cnt] = j+1;
      permutation(cnt+1);
      vist[j] = false;
    }
  }
  
}