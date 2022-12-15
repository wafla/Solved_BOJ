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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            sum += x;
        }
        for (int i = n; i > 0; i--)
        {
            if (sum % i == 0)
            {
                int ssum = 0;
                int check = 0;
                for (int j = 0; j < v.size(); j++)
                {
                    ssum += v[j];
                    if (ssum == sum / i)
                    {
                        ssum = 0;
                        continue;
                    }
                    else if (ssum > sum / i)
                    {
                        check = 1;
                        break;
                    }
                }
                if (!check)
                {
                    cout << sum / i << '\n';
                    break;
                }
            }
        }
    }
}