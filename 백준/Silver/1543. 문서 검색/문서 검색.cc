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
    bool v[2501] = { 0 };
    string str, s;
    getline(cin, str);
    getline(cin, s);
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (!v[i])
        {
            int check = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (str[i + j] != s[j] || i + j >= str.size())
                {
                    check = 1;
                    break;
                }
            }
            if (!check)
            {
                ans++;
                for (int j = i; j < i + s.size(); j++)
                    v[j] = 1;
            }
        }
    }
    cout << ans;
}