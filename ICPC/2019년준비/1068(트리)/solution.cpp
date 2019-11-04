#include <cstdio>
#include <vector>
using namespace std;
int n, par, root, del, ans;
vector<vector<int> > tree;

void find(int node){
    int child = 0;
    int cn = tree[node].size();
    for(int i = 0; i < cn; i++){
        int x = tree[node][i];
        if(x == del)continue;
        find(x); child++;
    }
    if(!child)ans++;
}

int main(){
    scanf("%d", &n);
    tree = vector<vector<int> >(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &par);
        if(par == -1){
            root = i;
            continue;
        }
        tree[par].push_back(i);
    }
    scanf("%d", &del);
    if(root == del)printf("0");
    else{
        find(root);
        printf("%d", ans);
    }
}