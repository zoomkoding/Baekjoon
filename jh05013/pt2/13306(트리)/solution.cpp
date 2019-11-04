#include <cstdio>
#include <vector>

using namespace std;

int n, ans_n, q, x, a, b, c, d, par[200001], temp[200001], data[400002][2];

int find(int i){
    if(par[i] == i)return i;
    return par[i] = find(par[i]);
}

int main(){
    scanf("%d %d", &n, &q);
    vector<int> ans(q);
    par[1] = 1, temp[1] = 1;
    for(int i = 2; i <= n; i++){
        scanf("%d", &temp[i]);
        par[i] = i;
    }
    for(int i = 0; i < n + q - 1; i++){
        scanf("%d", &x);
        if(x) scanf("%d %d", &data[i][0], &data[i][1]);
        else scanf("%d", &data[i][0]);
    }
    for(int i = n + q - 2; i >= 0; i--){
        if(data[i][1]) ans[ans_n++] = find(data[i][0]) == find(data[i][1]);
        else par[data[i][0]] = temp[data[i][0]];
    }
    for(int i = ans.size() - 1; i >= 0; i--)printf("%s\n", ans[i] ? "YES" : "NO");
}