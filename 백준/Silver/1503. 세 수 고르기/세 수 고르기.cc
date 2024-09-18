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
#include <unordered_map>
#include <tuple>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
#define ti tuple<int, int, int>
using namespace std;
bool num[1001] = { 0 };
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        num[tmp] = 1;
    }

    int ans = INF;
    for (int i = 1; i <= 1001; i++)
    {
        if (num[i])
            continue;
        for (int j = 1; j <= 1001; j++)
        {
            if (num[j])
                continue;
            for (int k = 1; k <= 1001; k++)
            {
                if (num[k])
                    continue;
                int xyz = i * j * k;
                ans = min(ans, abs(n - xyz));
                if (n < xyz)
                    break;
            }
        }
    }
    cout << ans << '\n';
}