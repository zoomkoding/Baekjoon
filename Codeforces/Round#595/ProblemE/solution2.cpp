#include <cstdio>
#include <algorithm>
using namespace std;
int n, c, temp, a[200002], b[200002], ans[200001][2];
int main(){
    scanf("%d %d", &n, &c);
    for(int i = 1; i < n; i++)scanf("%d", &a[i]);
    for(int i = 1; i < n; i++)scanf("%d", &b[i]);
    ans[0][0] = c;
    for(int i = 1; i < n; i++){
        ans[i][0] = min(ans[i-1][0] + b[i], ans[i-1][1] + b[i] + c);
        ans[i][1] = min(ans[i-1][0] + a[i], ans[i-1][1] + a[i]);
    }
    for(int i = 0; i < n; i++)printf("%d ", min(ans[i][0], ans[i][1]));
}