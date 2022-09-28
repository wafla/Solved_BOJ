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
    ll x, y, w, s;
    cin >> x >> y >> w >> s;
    ll ans = 0;
    ll minn = min(x, y);
    if (2 * w < s)
        ans += 2 * w * minn;
    else
        ans += s * minn;
    x -= minn;
    y -= minn;
    if (x > 0)
    {
        int check = 0;
        if (x % 2 == 1)
        {
            x--;
            check++;
        }
        if (2 * w < 2 * s)
            ans += 2 * w * x/2;
        else
            ans += 2 * s * x/2;
        if (check)
            ans += w;
    }
    else if (y > 0)
    {
        int check = 0;
        if (y % 2 == 1)
        {
            y--;
            check++;
        }
        if (2 * w < 2 * s)
            ans += 2 * w * y/2;
        else
            ans += 2 * s * y/2;
        if (check)
            ans += w;
    }
    cout << ans;
}