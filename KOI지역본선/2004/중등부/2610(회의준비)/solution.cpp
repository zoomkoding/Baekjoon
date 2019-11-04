#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 100000
int n, m, v1, v2, arr[101][101], par[101], rep[101], rev[101];
int find(int x){
    if(par[x] == x)return x;
    return par[x] = find(par[x]);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)arr[i][j] = 100000;
        rev[i] = INF, rep[i] = -1, par[i] = i, arr[i][i] = 0;

    }
    while(m--){
        scanf("%d %d", &v1, &v2);
        arr[v1][v2] = arr[v2][v1] = 1;
        int p1 = find(v1), p2 = find(v2);
        if(p1 != p2)par[p1] = p2;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] + arr[k][j] < arr[i][j])arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int p1 = find(i), max = -1;
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == INF)continue;
            if(max < arr[i][j])max = arr[i][j];
        }
        if(rev[p1] > max)rev[p1] = max, rep[p1] = i;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(rep[i] != -1) ans.push_back(rep[i]);
    }
    sort(ans.begin(), ans.end());
    printf("%lu\n", ans.size());
    for(int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);
}