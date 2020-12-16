#include <stdio.h>

int main()
{
		int i,cases;
		unsigned int pos1,pos2;
		unsigned int x[3];
		unsigned int y[3];
	
		scanf("%d",&cases);
		while(cases--)
		{
				for(i=0;i<3;i++)
						scanf("%u %u",&x[i],&y[i]);
				pos1=x[0]^x[1]^x[2];
				pos2=y[0]^y[1]^y[2];
				printf("%u %u\n",pos1,pos2);
		}
		return 0;
}