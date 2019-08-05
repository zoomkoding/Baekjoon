//??? ?? ???? ??????!
//zoomkoding.github.io/codingtest/2019/08/05/baekjoon-10217.html

#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define pip pair<int, pii>
#define X first
#define Y second
#define D Y.X
#define C Y.Y
#define INF 10000000
using namespace std;


char buf[1 << 17];

inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? sum : -sum;
}

int t, n, m, k, u, v, d, c, ans;

int main(){
    t = readInt();
    while(t--){
        ans = INF;
        n = readInt(), m = readInt(), k = readInt();
        vector<vector<pip> >adj(n + 1);
        vector<vector<int> > dist(101, vector<int>(10001, INF));
        while(k--){
            u =readInt(), v = readInt(), c = readInt(), d = readInt();
            adj[u].push_back(pip(v, pii(d, c)));
        }
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        dist[1][0] = 0;
        pq.push(pii(0, 1));
        while(!pq.empty()){
            pii top = pq.top(); pq.pop();
            int ti = top.Y, tc = top.X;
            int td = dist[ti][tc];
            if(ti == n){
                ans = min(td, ans);
                continue;
            }
            for(int i = 0; i < adj[ti].size(); i++){
                int ni = adj[ti][i].X, nc = tc + adj[ti][i].C, nd = adj[ti][i].D + td;
                if(nc > m || nd >= ans) continue;
                if(dist[ni][nc] > nd){
                    dist[ni][nc] = nd;
                    pq.push(pii(nc, ni));
                }
            }
        }
        if(ans == INF) printf("Poor KCM\n");
        else printf("%d\n", ans);
            
    }
}