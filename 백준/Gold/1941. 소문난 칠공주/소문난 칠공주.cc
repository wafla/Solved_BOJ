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
char arr[6][6] = { 0 };
int selected[25] = { 0 };
int visit[6][6] = { 0 };
int visit2[6][6] = { 0 };
int ans = 0;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int cnt_dfs = 0;
void dfs(int x, int y)
{
    visit2[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;
        if (visit[nx][ny] == 1 && visit2[nx][ny] == 0)
        {
            cnt_dfs++;
            dfs(nx, ny);
        }
    }
}
void solve(int idx, int t, int s)
{
    if (t == 7)
    {
        if (s < 4)
            return;
        memset(visit, 0, sizeof(visit));
        memset(visit2, 0, sizeof(visit2));
        cnt_dfs = 0;
        for (int i = 0; i < 25; i++)
        {
            int r = i / 5;
            int c = i % 5;
            if (selected[i])
                visit[r][c] = 1;
        }
        for (int i = 0; i < 25; i++)
            if (selected[i])
            {
                cnt_dfs++;
                dfs(i / 5, i % 5);
                if (cnt_dfs == 7)
                    ans++;
                break;
            }
        return;
    }
    for (int i = idx; i < 25; i++)
    {
        selected[i] = 1;
        solve(i + 1, t + 1, s + (arr[i / 5][i % 5] == 'S'));
        selected[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    solve(0, 0, 0);
    cout << ans;
}