#include <stdio.h>
#define min(a,b) (a > b ? b : a);
int arr[1001][3] = { 0 }, dp[1001][3] = { 0 };
int main()
{
	int n, i, j, a;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);
	dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				dp[i][j] += min(dp[i - 1][1] + arr[i][j], dp[i - 1][2] + arr[i][j]);
			}
			else if (j == 1)
			{
				dp[i][j] += min(dp[i - 1][0] + arr[i][j], dp[i - 1][2] + arr[i][j]);
			}
			else if (j == 2)
			{
				dp[i][j] += min(dp[i - 1][1] + arr[i][j], dp[i - 1][0] + arr[i][j]);
			}
		}
	}
	a = dp[n-1][0] > dp[n-1][1] ? dp[n-1][1] : dp[n-1][0];
	if (a > dp[n-1][2])
		a = dp[n-1][2];
	printf("%d", a);
}