#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
int arr[4001][4001] = { 0 };
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int ans = 0;
	string a, b;
	cin >> a >> b;
	for (int i = 1;i <= a.size();i++)
	{
		for (int j = 1;j <= b.size();j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
				if (arr[i][j] > ans)
					ans = arr[i][j];
			}
		}
	}
	cout << ans;
}
//참고 : https://lmcoa15.tistory.com/73