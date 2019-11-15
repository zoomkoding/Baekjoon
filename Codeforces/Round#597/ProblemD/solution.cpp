#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<ll, ll>
#define pip pair<ll, pii>
using namespace std;
ll ans, n, x[2001], y[2001], c[2001], k[2001], visited[2001];
vector<pii> elist;
vector<ll> clist;
int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)scanf("%lld %lld", &x[i], &y[i]);
    for(int i = 1; i <= n; i++)scanf("%lld", &c[i]);
    for(int i = 1; i <= n; i++)scanf("%lld", &k[i]);
    priority_queue<pip> pq;
    for(int i = 1; i <= n; i++)pq.push(pip(-c[i], pii(0, i)));
    while(!pq.empty()){
        pip top = pq.top(); pq.pop();
        long long cur = top.second.second;
        if(visited[cur])continue;
        visited[cur] = 1;
        if(top.second.first == 0)clist.push_back(cur);
        else elist.push_back(pii(top.second.first, cur));
        ans += -top.first;
        for(int i = 1; i <= n; i++){
            if(cur == i || visited[i])continue;
            long long d = abs(x[cur] - x[i]) + abs(y[cur] - y[i]);
            pq.push(pip(-d * (k[cur] +k[i]), pii(cur, i)));
        }
    }
    printf("%lld\n", ans);
    printf("%lu\n", clist.size());
    for(int i = 0; i < clist.size(); i++)printf("%lld ", clist[i]);
    printf("\n%lu\n", elist.size());
    for(int i = 0; i < elist.size(); i++)printf("%lld %lld\n", elist[i].first, elist[i].second);
}