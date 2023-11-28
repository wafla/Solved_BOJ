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
//#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
    sort(v.begin(), v.end());
	for (int i = 0; i < k; i++)
	{
		int L, R, X;
		cin >> L >> R >> X;
		L--; R--;
		vector<int> v1, v2;
		for (int j = 0; j < n; j++)
		{
			if (j >= L && j <= R)
				v1.push_back(v[j] + X);
			else
				v2.push_back(v[j]);
		}
		int idx = 0, idx1 = 0, idx2 = 0;
		while (idx1 < v1.size() && idx2 < v2.size())
		{
			if (v1[idx1] < v2[idx2])
				v[idx++] = v1[idx1++];
			else
				v[idx++] = v2[idx2++];
		}
		while (idx1 < v1.size())
			v[idx++] = v1[idx1++];
		while (idx2 < v2.size())
			v[idx++] = v2[idx2++];
	}
	for (auto i : v)
		cout << i << " ";
}
// 참고 : https://ongveloper.tistory.com/374