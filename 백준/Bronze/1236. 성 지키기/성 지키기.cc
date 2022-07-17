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
#define INF 987654321
#define MOD 1000000007
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    char arr[51][51] = { 0 };
    int r[51] = { 0 }, c[51] = { 0 };
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'X')
            {
                r[i]++;
                c[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (r[i] == 0 && c[j] == 0)
            {
                r[i]++;
                c[j]++;
                ans++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (r[i] == 0)
            ans++;
    for(int i=0;i<m;i++)
        if (c[i] == 0)
            ans++;
    cout << ans;
}