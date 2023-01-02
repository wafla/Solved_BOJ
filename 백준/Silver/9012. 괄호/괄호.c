#include <stdio.h>
int main()
{
	int n, i, s;
	char a[50] = { 0 };
	scanf("%d", &n);
	while (n--)
	{
		s = 0;
		scanf("%s", &a);
		for (i = 0; i < 50; i++)
		{
			if (a[i] == '(')
				s++;
			else if (a[i] == ')')
			{
				s--;
				if (s < 0)
					break;
			}
			else
				break;
		}
		for (i = 0; i < 50; i++)
			a[i] = 0;
		if (s == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}//난 병신인가보다 if에 == 를 안하고 있었네