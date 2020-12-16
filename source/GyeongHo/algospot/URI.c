#include <stdio.h>
#include <string.h>

int main()
{
	int C;
	scanf("%d", &C);

	while(C--)
	{
		char str[81];
		scanf("%s", str);
		for (int i = 0 ; i < 80 ; i++)
		{
			if (str[i] == '\0')
			{
				printf("\n");
				break;
			}
			if (str[i] == '%')
			{
				i++;
				if (str[i] == '2')
				{
					i++;
					if (str[i] == '0') printf(" ");
					else if (str[i] == '1') printf("!");
					else if (str[i] == '4') printf("$");
					else if (str[i] == '5') printf("%%");
					else if (str[i] == '8') printf("(");
					else if (str[i] == '9') printf(")");
					else if (str[i] == 'a') printf("*");
				}
			}
			else
				printf("%c", str[i]);
		}
	}
	return 0;
}