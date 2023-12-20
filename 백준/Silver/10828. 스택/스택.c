#include <stdio.h>
#include <string.h>
int a[10001] = { 0 }, p = 0;
void push(int x)
{
	a[p] = x;
	p++;
}
void pop()
{
	if (a[p - 1] == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", a[p - 1]);
		a[p - 1] = 0;
		p--;
	}
}
void size()
{
	int i = 0;
	while (a[i] != 0)
		i++;
	printf("%d\n", i);
}
void empty()
{
	if (a[0] == 0)
		printf("1\n");
	else
		printf("0\n");
}
void top()
{
	if (a[p - 1] == 0)
		printf("-1\n");
	else
		printf("%d\n", a[p - 1]);
}
int main()
{
	int n, z, i;
	char x[5][6] = { "push","pop","size","empty","top" }, h[6] = { 0 };
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", h);
		for (i = 0; i < 5; i++)
		{
			if (strcmp(x[i], h) == 0)
			{
				if (i == 0)//push
				{
					scanf("%d", &z);
					push(z);
				}
				if (i == 1)//pop
					pop();
				if (i == 2)//size
					size();
				if (i == 3)//empty
					empty();
				if (i == 4)//top
					top();
			}
		}
		for (i = 0; i < 6; i++)
			h[i] = 0;
	}
}