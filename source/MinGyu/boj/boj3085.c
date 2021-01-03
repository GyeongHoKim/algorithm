include <stdio.h>
#include <string.h>
int maxCandy(char board[][51],int size);
int maxNum(int a,int b)
{
  if(a>b)
    return a;

  else
    return b;
}
int main()
{
  char tok;
  int size,result=0,max=0;
  char board[51][51];
  memset(board,0,sizeof(char)*51*51);
  scanf("%d",&size);
  
  for(int i=0;i<size;i++)
    scanf("%s",board[i]);
  
  for(int i=0;i<size;i++){
    for(int j=0;j<size-1;j++){
      tok=board[i][j];
      board[i][j]=board[i][j+1];
      board[i][j+1]=tok;

      max = maxCandy(board, size);
      result = maxNum(result, max);

      tok=board[i][j+1];
      board[i][j+1]=board[i][j];
      board[i][j]=tok;

      tok=board[i][j];
      board[i][j]=board[i+1][j];
      board[i+1][j]=tok;

      max = maxCandy(board, size);
      result = maxNum(result, max);

      tok=board[i+1][j];
      board[i+1][j]=board[i][j];
      board[i][j]=tok;

    }

  }
  printf("%d",result);
}

int maxCandy(char board[][51],int size)
{
  int count,result;
  result=0;

  for(int i=0;i<size;i++){
    count =1;
    for(int j=1;j<=size;j++){
      if(board[i][j-1]==board[i][j])
        count++;
      else
      {
        if(count>result)
          result = count;
        count = 1;
      }
    }
  }

  for(int i=0;i<size;i++){
    count = 1;
    for(int j=1;j<=size;j++){
      if(board[j-1][i]==board[j][i])
        count++;
      else
      {
        if(count>result)
          result = count;
        count = 1;
      }
    }
  }

  return result;
}