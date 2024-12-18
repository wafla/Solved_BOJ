#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <iostream>
using namespace std;
vector<vector<int>> v;
set<int> s1;
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int nx = v[x][i];
        if(!s1.count(nx))
        {
            s1.insert(nx);
            dfs(nx);
        }
    }
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    int s2;
    for(int i=0;i<wires.size();i++)
    {
        s2 = 0;
        v.clear();
        v.resize(n+1);
        for(int j=0;j<wires.size();j++)
        {
            if(i==j)
                continue;
            int x = wires[j][0];
            int y = wires[j][1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        s1.clear();
        for(int j=1;j<=n;j++)
        {
            if(!s1.count(j))
            {
                s1.insert(j);
                dfs(j);
                break;
            }
        }
        s2 = n - s1.size();
        answer = min(answer,abs(int(s1.size())-s2));
    }
    return answer;
}