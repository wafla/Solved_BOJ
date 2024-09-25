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
#include <sstream>
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int m, S = 0;
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        string s;
        int x;

        ss >> s;

        if (s == "add")
        {
            ss >> x;
            S |= (1 << x);
        }
        else if (s == "remove")
        {
            ss >> x;
            S &= ~(1 << x);
        }
        else if (s == "check")
        {
            ss >> x;
            if (S & (1<<x))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (s == "toggle")
        {
            ss >> x;
            if (S & (1 << x))
                S &= ~(1 << x);
            else
                S |= (1 << x);
        }
        else if (s == "all")
        {
            for (int i = 0; i < 21; i++)
                S = (1 << 21) - 1;
        }
        else if (s == "empty")
        {
            for (int i = 0; i < 21; i++)
                S = 0;
        }
    }
}
