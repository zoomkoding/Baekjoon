#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<vector<int>> nodeinfo;
vector<vector<int>> answer;
vector<int> v;

bool compare(int a, int b){
    return nodeinfo[a][0] <= nodeinfo[b][0];
}
void dfs(int begin, int end){
    int root = -1;
    int MAX = -1;
    for(int i = begin; i <= end; i++){
        if(nodeinfo[v[i]][1] > MAX)root = i, MAX = nodeinfo[v[i]][1];
    }
    if(root == -1)return;
    answer[0].push_back(v[root]+1);
    dfs(begin, root - 1);
    dfs(root + 1, end);
    answer[1].push_back(v[root]+1);
}


vector<vector<int>> solution(vector<vector<int>> _nodeinfo) {

    nodeinfo = _nodeinfo;
    for(int i = 0; i < nodeinfo.size(); i++)v.push_back(i);
    answer = vector< vector<int>>(2);
    sort(v.begin(), v.end(), compare);
    dfs(0, nodeinfo.size() - 1);
    return answer;
}