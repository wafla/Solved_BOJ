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
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
using namespace std;
pair<int, string> ans(string t)
{
    string result;

    result += "(";
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '(') 
            result += "((";
        else if (t[i] == ')') 
            result += "))";
        else if (t[i] == '+') 
            result += ")+(";
        else 
            result += t[i];
    }
    result += ")";

    return { result.size(), result };
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, p;
    cin >> n >> p;

    string s, t;
    cin >> s;
    t = s;

    pair<int, string> tmp = ans(t);
    cout << tmp.X << '\n' << tmp.Y << '\n';
}