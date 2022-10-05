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
    int n, ans = 0;
    cin >> n;
    deque<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    while (v.size() > 1)
    {
        ans++;
        if (v[0] == 1)
            v.pop_front();
        else
            v[0]--;
        int a = v.back();
        v.pop_back();
        int b = v.back();
        v.pop_back();
        v.push_back(a + b);
    }
    cout << ans;
}