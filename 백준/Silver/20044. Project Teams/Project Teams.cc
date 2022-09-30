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
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int minn = INF;
    for (int i = 0; i < n; i++)
        if (minn > v[i] + v[2 * n - i - 1])
            minn = v[i] + v[2 * n - i - 1];
    cout << minn;
}