#include <stdio.h>	
#include <string.h>

int main()
{
  int i,T;
  char sentence[101];

  scanf("%d",&T);
  while(T--)
  {
	scanf("%s",sentence);
	for(i=0;i<(int)strlen(sentence);i++)
	  if(i%2==0)
		printf("%c",sentence[i]);
	for(i=0;i<(int)strlen(sentence);i++)
	  if(i%2!=0)
		printf("%c",sentence[i]);
	if(T>0)
	  printf("\n");
  }
}