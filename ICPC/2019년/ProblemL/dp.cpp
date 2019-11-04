#include <cstdio>
#include <algorithm>
#include <functional>
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;

pii w[251];
int n, v1, v2;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &w[i].X, &w[i].Y);
    sort(w, w + n, greater<pii>());
    for(int i = 0; i < n; i++){
        int m1 = max(v1 + w[i].X, v2), m2 = max(v1, v2 + w[i].Y);
        if(m1 < m2) v1 += w[i].X;
        else v2 += w[i].Y;
    }
    printf("%d", max(v1, v2));
}