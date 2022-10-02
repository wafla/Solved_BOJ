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
    cout << "int a;\n";
    cout << "int *ptr = &a;\n";
    string s1 = "ptr2", s2 = "ptr";
    for (int i = 1; i < n; i++)
    {
        cout << "int ";
        for (int j = 0; j < i + 1; j++)
            cout << "*";
        cout << s1 << " = &";
        cout << s2 << ";\n";
        s2 = s1;
        s1 = "ptr" + to_string(i + 2);
    }
}