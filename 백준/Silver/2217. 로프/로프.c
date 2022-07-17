#include <stdio.h>
int main()
{
	int n, x, i, max = -1, a[100001] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		a[x]++;
	}
	for (i = 1; i < 100001; i++)
	{
		if (a[i] != 0)
		{
			x = n * i;
			if (x > max)
				max = x;
			n -= a[i];
		}
	}
	printf("%d", max);
}