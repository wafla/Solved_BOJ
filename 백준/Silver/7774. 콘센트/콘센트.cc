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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int maxx = 0;
	int cnt = 0; // 컴퓨터를 꼽을 수 있는 개수
	int b_cnt = 0; // A-B를 꼽을 수 있는 개수
	int x = a.back();
	a.pop_back();
	while (1)
	{
		while (x) // B-A를 최대한 꼽기
		{
			if (!b.empty())
			{
				cnt += b.back();
				b_cnt += b.back();
				b.pop_back();
			}
			else
				break;
			x--;
		}
		maxx = max(cnt, maxx);
		if (b_cnt > 0)
		{
			if (!a.empty()) // A-B 꼽고 다시 B-A 꼽으러 ㄱㄱ
			{
				cnt--;
				b_cnt--;
				x += a.back();
				a.pop_back();
			}
			else
				break;
		}
		else
			break;
	}
	cout << maxx << '\n';
}