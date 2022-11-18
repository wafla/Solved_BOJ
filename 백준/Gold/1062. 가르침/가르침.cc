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
int n, k;
int visit[26] = { 0 };
int ans = 0;
vector<string> v;
void check()
{
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int x = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (visit[v[i][j] - 97] == 0)
            {
                x = 1;
                break;
            }
        }
        if (!x)
            cnt++;
    }
    if (ans < cnt)
        ans = cnt;
}
void solve(int idx, int cnt)
{
    if (cnt >= k)
    {
        check();
        return;
    }
    if (idx >= 26)
        return;
    for (int i = idx; i < 26; i++)
    {
        if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19)
            continue;
        visit[i] = 1;
        solve(i + 1, cnt + 1);
        visit[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    if (k >= 5)
    {
        visit[0] = 1; // a
        visit[2] = 1; // c
        visit[8] = 1; // i
        visit[13] = 1; // n
        visit[19] = 1; // t
        k -= 5;
        solve(0, 0);
    }
    cout << ans;
}