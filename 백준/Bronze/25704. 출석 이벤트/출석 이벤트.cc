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
    int n, p;
    cin >> n >> p;
    int a = INF, b = INF, c = INF, d = INF, ans = p;
    if (n >= 5)
        a = p - 500;
    if (n >= 10)
        b = p - p / 10;
    if (n >= 15)
        c = p - 2000;
    if (n >= 20)
        d = p - p / 4;
    ans = min(a, min(b, min(c, min(d, ans))));
    if (ans < 0)
        cout << 0;
    else
        cout << ans;
}