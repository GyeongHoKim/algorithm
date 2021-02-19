#include <stdio.h>
#include <stdbool.h>

bool visit[8] = {false};
int list[8];
int arr[8];
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
  }
  
  bool check[10001] = {false,};

  for(int j=0; j<n; j++)
  {
    if(visit[j]==false && check[arr[j]]==false)
    {
      check[arr[j]] = true;
      list[cnt] = arr[j];
      visit[j] = true;
      backtrack(cnt+1);
      visit[j] = false;
    }
  }
  return;
}