#include <cstdio>
#include <algorithm>
using namespace std;
int par[100010], g, p, t, v, ans;
int find(int x) {
    if (x == par[x])return x;
    return par[x] = find(par[x]);
}
int main() {
    scanf("%d%d", &g, &p);
    for (int i = 0; i <= g; i++)
        par[i] = i;
    for (int i = 0; i < p; i++) {
        scanf("%d", &t);
        v = find(t);
        if (!v)break;
        par[v] = v - 1;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
