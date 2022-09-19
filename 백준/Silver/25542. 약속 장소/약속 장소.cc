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
	vector<string> v;
	string s;
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	string S;
	for (int i = 0; i < l; i++)
	{
		int arr[26] = { 0 };
		for (int j = 0; j < n; j++)
		{
			arr[v[j][i]-65]++;
		}
		vector<pair<int, int>> V;
		for (int j = 0; j < 26; j++)
			V.push_back({ arr[j], j });
		sort(V.begin(), V.end());
		reverse(V.begin(), V.end());
		S += V[0].Y + 65;
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < l; j++)
		{
			if (v[i][j] != S[j])
				cnt++;
		}
		if (cnt > 1)
		{
			cout << "CALL FRIEND";
			return 0;
		}
	}
	cout << S;
}