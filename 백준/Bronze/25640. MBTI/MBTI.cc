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
    string s;
    cin >> s;
    int n;
    cin >> n;
    int ans = 0;
    set<string> S;
    S.insert(s);
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (S.count(str))
            ans++;
    }
    cout << ans;
}