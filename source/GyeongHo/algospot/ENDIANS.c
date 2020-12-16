#include <stdio.h>

unsigned int convert(const unsigned int num)
{
		unsigned int first = num>>24;
		unsigned int second = (num>>16)-(first<<8);
		unsigned int fourth = num<<24;
		unsigned int third = (num<<16)-(fourth>>8);
		return first+(second<<8)+(third>>8)+fourth;
}

	int main()
{
		int C;
		scanf("%d",&C);

		while(C--)
		{
				unsigned int num;
				scanf("%u",&num);

				printf("%u\n",convert(num));
		}
		return 0;
}