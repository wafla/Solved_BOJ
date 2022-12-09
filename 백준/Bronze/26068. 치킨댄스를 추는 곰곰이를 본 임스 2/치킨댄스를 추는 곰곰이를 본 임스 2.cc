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
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.size() >= 5)
            continue;
        else if (s.size() == 3)
            cnt++;
        else
        {
            int a = s[2] - 48;
            int b = s[3] - 48;
            a *= 10;
            if (a + b <= 90)
                cnt++;
        }
    }
    cout << cnt;
}