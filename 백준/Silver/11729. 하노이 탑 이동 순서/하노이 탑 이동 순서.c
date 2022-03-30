#include <stdio.h>
void hanoi(int n, int from, int by, int to)
{
	if (n == 0)
		return 0;
	hanoi(n - 1, from, to, by);
	printf("%d %d\n", from, to);
	hanoi(n - 1, by,from,to);
}
int pow(int n)
{
	int i, a=1;
	for (i = 0; i < n; i++)
		a = a * 2;
	return a;
}
int main()
{
	int n, ans;
	scanf("%d", &n);
	ans = pow(n) - 1;
	printf("%d\n", ans);
	hanoi(n, 1, 2, 3);
}