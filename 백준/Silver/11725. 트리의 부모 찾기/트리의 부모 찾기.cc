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
map<int, vector<int>> M;
int ans[100001] = { 0 };
bool visit[100001] = { 0 };
void dfs(int idx)
{
    visit[idx] = 1;
    for (int j = 0; j < M[idx].size(); j++)
    {
        if (visit[M[idx][j]] == 0)
        {
            ans[M[idx][j]] = idx;
            dfs(M[idx][j]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (visit[i] == 0)
            dfs(i);
    for (int i = 2; i <= n; i++)
        cout << ans[i] << '\n';
}