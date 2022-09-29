#include <stdio.h>
int main()
{
	char a[101] = { 0 };
	int i, n=0;
	scanf("%s", &a);
	for (i = 0; a[i] != 0; i++)
	{
		if (a[i] == 99)
		{
			if (a[i + 1] == 45 || a[i + 1] == 61)
			{
				n++;
				i++;
			}
			else
				n++;
		}
		else if (a[i] == 100)
		{
			if (a[i + 1] == 122 && a[i + 2] == 61)
			{
				n++;
				i += 2;
			}
			else if (a[i + 1] == 45)
			{
				n++;
				i++;
			}
			else
				n++;
		}
		else if (a[i] == 108)
		{
			if (a[i + 1] == 106)
			{
				n++;
				i++;
			}
			else
				n++;
		}
		else if (a[i] == 110)
		{
			if (a[i + 1] == 106)
			{
				n++;
				i++;
			}
			else
				n++;
		}
		else if (a[i] == 115)
		{
			if (a[i + 1] == 61)
			{
				n++;
				i++;
			}
			else
				n++;
		}
		else if (a[i] == 122)
		{
			if (a[i + 1] == 61)
			{
				n++;
				i++;
			}
			else
				n++;
		}
		else
			n++;
	}
	printf("%d", n);
}