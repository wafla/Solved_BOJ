#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool visited[201]={0};
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    auto dfs = [&](int node, auto&& dfs_ref) -> void {
        visited[node] = true;
        for (int i = 0; i < n; i++) {
            if (computers[node][i] && !visited[i]) {
                dfs_ref(i, dfs_ref);
            }
        }
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<computers[i].size();j++){
            if(computers[i][j] && !visited[i]){
                dfs(i, dfs);
                answer++;
            }
        }
    }
    return answer;
}