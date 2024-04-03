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
#define int long long
#define pi pair<int, int>
#define T pair<int, pair<int, int>>
using namespace std;
vector<int> v, p;
int find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b)
		return;
	p[a] = b;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, q;
	cin >> n >> q;

	v.resize(n + 1);
	p.resize(n + 1);
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		v[i] = x;
	}

	vector<T> arr;
	for (int i = 1; i < n + q; i++)
	{
		int x;
		cin >> x;
		if (x == 0) // 부모와의 간선 제거
		{
			int b;
			cin >> b;
			arr.push_back({ x,{b,0} });
		}
		else // c와 d를 연결하는 경로가 있는지
		{
			int c, d;
			cin >> c >> d;
			arr.push_back({ x,{c,d} });
		}
	}
	
	for (int i = 1; i <= n; i++) // 유니온-파인드 초기화
		p[i] = i;

	vector<string> ans;
	reverse(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].X == 0) // 연결하기
			merge(arr[i].Y.X, v[arr[i].Y.X]);
		else // 연결돼있는지 확인
		{
			if (find(arr[i].Y.X) == find(arr[i].Y.Y))
				ans.push_back("YES\n");
			else
				ans.push_back("NO\n");
		}
	}

	reverse(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i;
	cout << '\n';
}
// 참고 : https://cat-holic0713.tistory.com/2