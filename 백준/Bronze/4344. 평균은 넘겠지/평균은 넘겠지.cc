#include <stdio.h>
int main()
{
	int a, arr[1001] = { 0 }, sum = 0, b, c = 0;
	float num;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		for (int j = 0; j < b; j++)
		{
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		num = float(sum) / float(b);
		sum = 0;
		for (int j = 0; j < b; j++)
		{
			if (arr[j] > num)
			{
				c += 1;
			}
		}
		float x = float(c) / float(b) * 100;
		c = 0;
		printf("%.3f%\n", x);
	}
}