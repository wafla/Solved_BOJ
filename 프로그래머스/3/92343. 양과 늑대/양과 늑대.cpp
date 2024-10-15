#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define X first
#define Y second
using namespace std;
struct Node {
	int left = -1;
	int right = -1;
};
vector<Node> v;
vector<bool> visited(18);
int solution(vector<int> info, vector<vector<int>> edges) {
    v.resize(info.size());
	for(int i=0;i<edges.size();i++)
    {
        int parent = edges[i][0];
        int child = edges[i][1];
        if(v[parent].left==-1)
            v[parent].left = child;
        else
            v[parent].right = child;
    }
    
    int ans = 1;
    queue<pair<pair<int,int>, pair<int, vector<int>>>> Q; // 양, 늑대, 정답, 다음 노드
    vector<int> tmp;
    if(v[0].left!=-1)
        tmp.push_back(v[0].left);
    if(v[0].right!=-1)
        tmp.push_back(v[0].right);
    Q.push({{1,0},{1,tmp}});
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        int sheep = cur.X.X;
        int wolf = cur.X.Y;
        int cnt = cur.Y.X;
        vector<int> nodes = cur.Y.Y;
        if(wolf >= sheep)
            continue;
        if(ans < cnt)
            ans = cnt;
        for(int i=0;i<nodes.size();i++)
        {
            int nx = nodes[i];
            vector<int> next_nodes = nodes;
            next_nodes.erase(next_nodes.begin()+i);
            if(v[nx].left!=-1)
                next_nodes.push_back(v[nx].left);
            if(v[nx].right!=-1)
                next_nodes.push_back(v[nx].right);
            if(info[nx])
                Q.push({{sheep, wolf+1},{cnt, next_nodes}});
            else
                Q.push({{sheep+1, wolf},{cnt+1,next_nodes}});
        }
    }
    
	return ans;
}
