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
        priority_queue<int> PQ;
        priority_queue<int, vector<int>, greater<int>> PQ2;
        map<int, int> M;
        while (n--)
        {
            char q;
            int x;
            cin >> q >> x;
            if (q == 'I')
            {
                PQ.push(x);
                PQ2.push(x);
                M[x]++;
            }
            else if(q == 'D')
            {
                if (x == 1)
                {
                    while (!PQ.empty())
                    {
                        if (M[PQ.top()] == 0)
                            PQ.pop();
                        else
                            break;
                    }
                    if (PQ.size() == 0)
                        continue;
                    M[PQ.top()]--;
                    PQ.pop();
                }
                else if (x == -1)
                {
                    while (!PQ2.empty())
                    {
                        if (M[PQ2.top()] == 0)
                            PQ2.pop();
                        else
                            break;
                    }
                    if (PQ2.size() == 0)
                        continue;
                    M[PQ2.top()]--;
                    PQ2.pop();
                }
            }
        }
        while (!PQ.empty())
        {
            if (M[PQ.top()] == 0)
                PQ.pop();
            else
                break;
        }
        while (!PQ2.empty())
        {
            if (M[PQ2.top()] == 0)
                PQ2.pop();
            else
                break;
        }
        if (PQ.size() == 0 || PQ2.size() == 0)
            cout << "EMPTY\n";
        else
            cout << PQ.top() << " " << PQ2.top() << '\n';
    }
}