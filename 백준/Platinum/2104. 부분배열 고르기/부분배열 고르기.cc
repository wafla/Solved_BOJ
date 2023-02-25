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
int n;
ll arr[100001] = { INF };
vector<pair<ll,ll>> tree;
pair<ll, ll> init(int node, int start, int end)
{
	if (start == end)
		return tree[node] = { arr[start],start };
	int mid = start + (end - start) / 2;
	pair<ll, ll> left = init(node * 2, start, mid);
	pair<ll, ll> right = init(node * 2 + 1, mid + 1, end);
	return tree[node] = { left.X + right.X, (arr[left.Y] < arr[right.Y]) ? left.Y : right.Y };
}
pair<ll, ll> solve(int node, int st, int en, int left, int right)
{
	if (en < left || right < st)
		return { 0,0 };
	if (left <= st && en <= right)
		return { tree[node].X, tree[node].Y };
	int mid = st + (en - st) / 2;
	pair<ll, ll> leftVal = solve(node * 2, st, mid, left, right);
	pair<ll, ll> rightVal = solve(node * 2 + 1, mid + 1, en, left, right);
	return { leftVal.X + rightVal.X, (arr[leftVal.Y] < arr[rightVal.Y]) ? leftVal.Y : rightVal.Y };
}
ll Div(int left, int right)
{
	if (left == right)
		return arr[left] * arr[left];
	auto cur = solve(1, 1, n, left, right);
	ll ans = cur.X * arr[cur.Y];
	if (cur.Y - 1 >= left)
		ans = max(ans, Div(left, cur.Y - 1));
	if (cur.Y + 1 <= right)
		ans = max(ans, Div(cur.Y + 1, right));
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	tree.resize(n * 4);
	init(1, 1, n);
	cout << Div(1, n) << '\n';
}
// 참고 : https://nicotina04.tistory.com/132
// https://github.com/Geniemo/BOJ/blob/master/2104.cpp