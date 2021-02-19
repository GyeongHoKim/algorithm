#include <stdio.h>

int whatYear(int E,int S,int M)
{
  int rE,rS,rM;
  rE = 1; rS = 1; rM = 1;
  int count = 1;
  while(1)
  {
    if(rE==E && rS==S && rM==M)
      return count;
    else
    {
      rE++;
      rS++;
      rM++;
      count++;

      if(rE==16)
        rE = 1;
      if(rS==29)
        rS = 1;
      if(rM==20)
        rM = 1;
    }
  }
}
int main()
{
  int E,S,M,year;
  scanf("%d %d %d",&E,&S,&M);
  year = whatYear(E,S,M);
  printf("%d",year);

}