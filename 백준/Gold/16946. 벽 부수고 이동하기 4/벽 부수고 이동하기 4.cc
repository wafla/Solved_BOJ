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
#define x first
#define y second
using namespace std;
int arr[1001][1001] = { 0 }, dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }, value[500001] = { 0 };
int n, m, cnt, v[1001][1001] = { 0 }, z = 0;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	string s;
	for (int i = 0;i < n;i++) {
		cin >> s;
		for (int j = 0;j < m;j++)
			arr[i][j] = s[j] - '0';
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (arr[i][j] == 0 && v[i][j] == 0)//0인 값들 그룹화하기
			{
				z++;
				int num = 0;
				queue<pair<int, int>> B;
				B.push({ i,j });
                		v[i][j]=z;
				while (!B.empty())
				{
					auto cur = B.front();
					B.pop();
					num++;
					for (int k = 0;k < 4;k++)
					{
						int nx = cur.x + dx[k];
						int ny = cur.y + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m)
							if (arr[nx][ny] == 0 && v[nx][ny] == 0)
                           				 {
                                				v[nx][ny]=z;
                                				B.push({ nx,ny });
                            				}
					}
				}
				value[z] = num;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (arr[i][j] == 1)
			{
				int num = 1;
				set<int> s;
				for (int k = 0;k < 4;k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m)
						if (arr[nx][ny] == 0 && v[nx][ny] > 0)
							s.insert(v[nx][ny]);
				}
				for (auto k : s)
					num += value[k];
				arr[i][j] = num % 10;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
			cout << arr[i][j];
		cout << '\n';
	}
}
