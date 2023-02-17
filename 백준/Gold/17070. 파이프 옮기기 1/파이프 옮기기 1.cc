#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
using namespace std;
int arr[17][17] = { 0 }, v[17][17] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	int cnt = 0;
	queue<pair<pair<int, int>, int>> Q; // 1 - 가로, 2 - 세로, 3 - 대각선
	Q.push({ {0,1},1 });
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int i = cur.X.X;
		int j = cur.X.Y;
		if (i == n - 1 && j == n - 1)
		{
			cnt++;
			continue;
		}
		if (cur.Y == 1)
		{
			if (j >= n - 1)
				continue;
			if (arr[i][j + 1] != 1) // 가 - 가
				Q.push({ {i,j + 1},1 });
			if (arr[i + 1][j + 1] != 1 && arr[i+1][j] != 1 && arr[i][j+1] != 1) // 가 - 대
				Q.push({ {i + 1,j + 1},3 });
		}
		else if (cur.Y == 2)
		{
			if (i >= n - 1)
				continue;
			if (arr[i + 1][j] != 1) // 세 - 세
				Q.push({ {i + 1,j},2 });
			if (arr[i + 1][j + 1] != 1 && arr[i + 1][j] != 1 && arr[i][j + 1] != 1) // 세 - 대
				Q.push({ {i + 1,j + 1},3 });
		}
		else if (cur.Y == 3)
		{
			if(j < n - 1)
				if (arr[i][j + 1] != 1) // 대 - 가
					Q.push({ {i,j + 1},1 });
			if(i < n - 1)
				if (arr[i + 1][j] != 1) // 대 - 세
					Q.push({ {i + 1,j},2 });
			if(i < n - 1 && j < n - 1)
				if (arr[i + 1][j + 1] != 1 && arr[i + 1][j] != 1 && arr[i][j + 1] != 1) // 대 - 대
					Q.push({ {i + 1,j + 1},3 });
		}
	}
	cout << cnt << '\n';
}