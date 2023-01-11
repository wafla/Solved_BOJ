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
int arr[500001] = { 0 };
int n, k, cnt = 0, ans = -1;
void merge(int left, int mid, int right)
{
	int i = left, j = mid + 1;
	vector<int> tmp;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			tmp.push_back(arr[i++]);
		else
			tmp.push_back(arr[j++]);
	}
	while (i <= mid)
		tmp.push_back(arr[i++]);
	while (j <= right)
		tmp.push_back(arr[j++]);
	int idx = left;
	for (int i = 0; i < tmp.size(); i++)
	{
		cnt++;
		arr[left++] = tmp[i];
		if (cnt == k)
		{
			ans = tmp[i];
			for (int i = 0; i < n; i++)
				cout << arr[i] << " ";
			cout << '\n';
		}
	}
}
void merge_sort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	merge_sort(0, n - 1);
	if (ans == -1)
		cout << -1 << '\n';
}