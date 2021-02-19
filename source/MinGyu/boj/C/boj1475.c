#include <stdio.h>

int main()
{
    char arrString[1000001];
    char arrNum[1000001];
    int i,j,set_count,rpo=0;
    i=0;set_count = 0;
    scanf("%s",arrString);

    while(arrString[i])
    {
      arrNum[i] = arrString[i]-'0';
      if(arrNum[i]==9)
        arrNum[i]=6;
      i++;
    }

    rpo = i;

    for(j=0;j<9;j++)
    {
      int set_num_count=0;
      for(int k=0;k<rpo;k++)
      {
       if(arrNum[k] == j)
        set_num_count += 1;
      }

      if(j==6)
      {
        if(set_num_count%2 ==1)
          set_num_count=(set_num_count/2)+1;
        else
          set_num_count /=2;
      }

      if(set_num_count>set_count)
        set_count = set_num_count;

    }

    printf("%d\n",set_count);
}