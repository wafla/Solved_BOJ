#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
int arr[7][3];
int tmp[7][3];
int flag;
vector<pi> v;
void count(int depth)
{
	if (depth == v.size())
		for (int i = 1; i <= 6; i++)
			for (int j = 0; j <= 2; j++)
				if (arr[i][j] != tmp[i][j])
					return;
	if (depth == v.size())
	{
		flag = 1;
		return;
	}
	int num = v[depth].X, idx = v[depth].Y;
	tmp[num][0]++; // 승
	tmp[idx][2]++;
	count(depth + 1);
	tmp[num][0]--;
	tmp[idx][2]--;

	tmp[num][2]++; // 패
	tmp[idx][0]++;
	count(depth + 1);
	tmp[num][2]--;
	tmp[idx][0]--;

	tmp[num][1]++; // 무
	tmp[idx][1]++;
	count(depth + 1);
	tmp[num][1]--;
	tmp[idx][1]--;
	return;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for (int i = 1; i <= 6; i++)
		for (int j = i + 1; j <= 6; j++)
			v.push_back({ i,j });
	int T = 4;
	while (T--)
	{
		memset(arr, 0, sizeof(arr));
		memset(tmp, 0, sizeof(tmp));
		flag = 0;
		for (int i = 1; i <= 6; i++)
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		count(0);
		if (flag)
			cout << "1 ";
		else
			cout << "0 ";
	}
	cout << '\n';
}
// 참고 : https://astrid-dm.tistory.com/510