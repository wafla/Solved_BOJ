#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define X first
#define Y second
#define pi pair<int,int>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    set<int> S;
    S.insert(1);
    vector<vector<pi>> v(N + 1);
    for(int i=0;i<road.size();i++)
    {
        int x = road[i][0];
        int y = road[i][1];
        int w = road[i][2];
        v[x].push_back({y,w});
        v[y].push_back({x,w});
    }
    priority_queue<pi, vector<pi>, greater<pi>> PQ; // sum, 마을 번호
    PQ.push({0, 1});
    vector<int> dist(N + 1, 987654321);
    dist[1]=0;
    while(PQ.size())
    {
        auto cur = PQ.top();
        PQ.pop();
        int sum = cur.X;
        int num = cur.Y;
        for(int i=0;i<v[num].size();i++)
        {
            int nx = v[num][i].X;
            int nw = v[num][i].Y;
            if(sum + nw < dist[nx] && sum + nw <= K)
            {
                dist[nx] = sum + nw;
                PQ.push({sum + nw, nx});
                if(!S.count(nx))
                    S.insert(nx);
            }
        }
    }
    answer = S.size();
    return answer;
}