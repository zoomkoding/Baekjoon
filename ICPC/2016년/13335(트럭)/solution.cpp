#include <cstdio>
#include <queue>
using namespace std;
int n, w, l, a[1001], ans;
int main(){
    scanf("%d %d %d", &n, &w, &l);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    queue<int> q;
    int sum = 0;
    for(int i = 0; i < n; i++){
        while(1){ 
            if(q.size() == w){
                sum -= q.front();
                q.pop();
            }
            if(sum + a[i] <= l) break;
            q.push(0);
            ans ++;
        }
        q.push(a[i]);
        sum += a[i];
        ans ++;
    }
    ans += w;
    printf("%d", ans); 
}