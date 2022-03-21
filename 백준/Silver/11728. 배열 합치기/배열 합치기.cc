#include <iostream>
using namespace std;
int main()
{
	//ios::sync_with_stdio();
	//cin.tie(0), cout.tie(0);
	int n, m, arr1[1000001] = { 0 }, arr2[1000001] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++)
		scanf("%d", &arr1[i]);
	for (int i = 0;i < m;i++)
		scanf("%d", &arr2[i]);
	int x = 0, y = 0;
	while(x < n && y < m)//투포인터로 수 비교 후 작은 수부터 출력
	{
		if (arr1[x] < arr2[y])
		{
			printf("%d ", arr1[x]);
			x++;
		}
		else
		{
			printf("%d ", arr2[y]);
			y++;
		}
	}
	while (x < n)
	{
		printf("%d ", arr1[x]);
		x++;
	}
	while (y < m)
	{
		printf("%d ", arr2[y]);
		y++;
	}
}