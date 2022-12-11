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
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0;
    while (v.size() > 1)
    {
        if (v[0] == 0)
            break;
        if (cnt > 1440)
        {
            cout << -1;
            return 0;
        }
        v[0]--;
        v[1]--;
        cnt++;
        if (v[1] == 0)
        {
            v.erase(v.begin() + 1);
            sort(v.begin(), v.end(), cmp);
        }
    }
    while (v.size() > 0)
    {
        if (v[0] == 0)
            break;
        if (cnt > 1440)
        {
            cout << -1;
            return 0;
        }
        v[0]--;
        cnt++;
    }
    if (cnt > 1440)
        cout << -1;
    else
        cout << cnt;
}