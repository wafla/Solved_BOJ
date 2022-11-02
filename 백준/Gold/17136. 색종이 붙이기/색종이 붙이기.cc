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
int arr[10][10] = { 0 };
int tmp[10][10] = { 0 };
int cnt = 0;
int paper[6];
int ans = INF;
bool check_map(int x, int y, int num)
{
    for (int i = x; i < x + num; i++)
        for (int j = y; j < y + num; j++)
            if (arr[i][j] == 0)
                return 0;
    return 1;
}
void fill_map(int x, int y, int num, int value)
{
    for (int i = x; i < x + num; i++)
        for (int j = y; j < y + num; j++)
            arr[i][j] = value;
}
void solve(int x, int y, int sum)
{
    while (arr[x][y] == 0)
    {
        y++;
        if (y == 10)
        {
            x++;
            y = 0;
            if (x == 10)
            {
                ans = min(ans, sum);
                return;
            }
        }
    }
    if (ans <= sum)
        return;
    for (int i = 5; i > 0; i--)
    {
        if (x + i > 10 || y + i > 10 || paper[i] == 0)
            continue;
        if (check_map(x, y, i))
        {
            fill_map(x, y, i, 0);
            paper[i]--;
            cnt -= i * i;
            solve(x, y, sum + 1);
            cnt += i * i;
            paper[i]++;
            fill_map(x, y, i, 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    for (int i = 0; i < 6; i++)
        paper[i] = 5;
    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                cnt++;
        }
    }
    solve(0, 0, 0);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}