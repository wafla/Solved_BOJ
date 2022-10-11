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
int arr[1501][1501] = { 0 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<pair<int,pair<int,int>>> v;
    for (int i = 0; i < n; i++)
        v.push_back({ arr[n - 1][i], {n - 1,i} });
    int ans, idx_i, idx_j;
    while (n--)
    {
        sort(v.begin(), v.end());
        ans = v[v.size() - 1].X;
        idx_i = v[v.size() - 1].Y.X;
        idx_j = v[v.size() - 1].Y.Y;
        v.pop_back();
        if (idx_i > 0)
            v.push_back({ arr[idx_i - 1][idx_j],{idx_i - 1,idx_j} });
    }
    cout << ans;
}