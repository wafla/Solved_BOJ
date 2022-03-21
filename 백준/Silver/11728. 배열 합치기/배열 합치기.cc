#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr1(n), arr2(m);
	for (int i = 0;i < n;i++)
		cin >> arr1[i];
	for (int i = 0;i < m;i++)
		cin >> arr2[i];
	int x = 0, y = 0;
	while(x < n && y < m)//투포인터로 수 비교 후 작은 수부터 출력
	{
		if (arr1[x] < arr2[y])
		{
			cout << arr1[x] << " ";
			x++;
		}
		else
		{
			cout << arr2[y] << " ";
			y++;
		}
	}
	while (x < n)
	{
		cout << arr1[x] << " ";
		x++;
	}
	while (y < m)
	{
		cout << arr2[y] << " ";
		y++;
	}
}