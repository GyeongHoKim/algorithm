#include <stdio.h>

int list[9];
int arr[9];
int n, m;

void backtrack(int cnt);
void sortbubble(int * arr)
{
  int temp;
  int len = n;

  for(int i=0; i<len -1; i++)
  {
    for(int j=0; j<(len-1)-i; j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  
  scanf("%d %d",&n ,&m);
  for(int i =0; i<n; i++)
    scanf("%d",&arr[i]);
  sortbubble(arr);
  backtrack(0);

}

void backtrack(int cnt) {
  if(cnt == m) {
    for(int i=0; i<m; i++)
    {
      printf("%d ",list[i]);
    }printf("\n");
    return;
  }

  for(int j=0; j<n; j++)
  {
      list[cnt] = arr[j];
      backtrack(cnt+1);
  }
  return;
}