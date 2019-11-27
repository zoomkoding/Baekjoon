#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define pii pair<int, int>
#define pip pair<int, pii>

int ans, cnt, n, t, h, arr[10001], visited[10001];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &arr[i]);
    scanf("%d %d", &t, &h);
    priority_queue<pip> pq;
    for(int i = 1; i <= n; i++){
        pq.push(pip(-h, pii(-1, i)));
        pq.push(pip(-arr[i] * t, pii(0, i)));
    }

    while(!pq.empty() || cnt != n){
        pip top = pq.top(); pq.pop();
        int v = -top.first, from = top.second.first, cur = top.second.second;
        if(visited[cur])continue;
        printf("%d %d %d\n", v, from, cur);
        ans += v, cnt++;
        visited[cur] = 1;
        if(from != -1)continue;
        for(int i = 1; i <= n; i++){
            if(visited[i])continue;
            pq.push(pip(-abs(arr[cur] - arr[i]) * t, pii(cur, i)));
        }
    }

    printf("%d", ans);
}