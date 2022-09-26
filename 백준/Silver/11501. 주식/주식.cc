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
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<ll,ll>> v(n);
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            arr[i] = x;
            v[i].X = x;
            v[i].Y = i;
        }
        sort(v.begin(), v.end(), cmp);
        ll ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ll maxx = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] >= v[j].X)
                    break;
                if (v[j].X - arr[i] > maxx)
                    if (v[j].Y > i)
                    {
                        maxx += v[j].X - arr[i];
                        break;
                    }
            }
            ans += maxx;
        }
        cout << ans << '\n';
    }
}