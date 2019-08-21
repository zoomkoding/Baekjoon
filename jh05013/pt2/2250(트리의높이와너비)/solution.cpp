#include <cstdio>
#include <vector>
#define pii pair<int, int>

using namespace std;

int max_lvl = 0, pos = 1, n, p, l, r, root = 1, par[10001], MIN[10001], MAX[10001];
vector<pii> v(10001);

void inorder(int root, int level){
    int left = v[root].first, right = v[root].second;
    if(level > max_lvl) max_lvl = level;
    if(left != -1)inorder(left, level + 1);
    if(MIN[level] > pos)MIN[level] = pos;
    if(MAX[level] < pos)MAX[level] = pos;
    pos ++;
    if(right != -1)inorder(right, level + 1);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &p, &l, &r);
        v[p] = pii(l, r);
        par[l] = par[r] = p;
    }
    while(par[root] != 0)root = par[root];
    for(int i = 1; i <= 10000; i++) MIN[i] = 100000, MAX[i] = 1;
    inorder(root, 1);
    int ans = 1;
    for(int i = 1; i <= max_lvl; i++){
        if(MAX[i] - MIN[i] > MAX[ans] - MIN[ans])ans = i;
    }
    printf("%d %d", ans, MAX[ans] - MIN[ans] + 1);
}