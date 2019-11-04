#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans, v1, v2, visited[100001];
vector< vector<int> > e;
int find(int x){
    int c = e[x].size();
    int used[6] = {0,};
    for(int i = 0; i < c; i++){
        int nx = e[x][i];
        if(visited[nx])continue;
        visited[nx] = 1;
        used[find(nx)] = 1;
    }
    for(int i = 1; i <= 5; i++){
        if(!used[i]){
            ans += i;
            return i;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    e = vector< vector<int> >(n + 1);
    for(int i = 0; i < n - 1; i++){
        cin >> v1 >> v2;
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    visited[1] = 1;
    find(1);
    cout << ans;
}