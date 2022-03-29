#include <stdio.h>
int main()
{
	int n, i = 1, k, s=0;
	scanf("%d", &n);
	while (i < n + 1)
	{
		k = i;
		while (k)
		{
			if (k % 10 == 3 || k % 10 == 6 || k % 10 == 9)
				s++;
			k /= 10;
		}
		i++;
	}
	printf("%d", s);
}