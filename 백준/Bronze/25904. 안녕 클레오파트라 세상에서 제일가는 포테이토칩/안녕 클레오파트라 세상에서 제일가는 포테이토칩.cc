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
    int n, x;
    cin >> n >> x;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int idx = 1;
    while (v[idx] >= x)
    {
        idx++;
        x++;
        if (idx == n + 1)
            idx = 1;
    }
    cout << idx;
}