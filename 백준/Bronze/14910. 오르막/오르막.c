#include <stdio.h>
int main()
{
	int n, x, i=-1000001;
	while (scanf("%d",&x)!=EOF)
	{
		if (i > x)
        {
            printf("Bad");
            return 0;
        }
		else 
            i=x;
	}
	printf("Good");
}