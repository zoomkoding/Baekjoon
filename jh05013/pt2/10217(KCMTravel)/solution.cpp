//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/08/05/baekjoon-10217.html

#include <cstdio>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;

typedef struct info{
    int x, d, c;
}info;

bool operator< (const info &a, const info &b) {
    return a.d > b.d;
}

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
        vector<vector<info> >adj(n + 1);
        vector<vector<int> > dist(101, vector<int>(10001, INF));
        while(k--){
            u =readInt(), v = readInt(), c = readInt(), d = readInt();
            adj[u].push_back({v, d, c});
        }
        priority_queue<info> pq;
        dist[1][0] = 0;
        pq.push({1, 0, 0});
        while(!pq.empty()){
            info top = pq.top(); pq.pop();
            int ti = top.x, tc = top.c, td = top.d;
            if(ti == n){
                ans = min(td, ans);
                continue;
            }
            for(info &t : adj[ti]){
                int ni = t.x, nc = t.c + tc, nd = t.d + td;
                if(nc > m || nd >= ans) continue;
                if(dist[ni][nc] > nd){
                    dist[ni][nc] = nd;
                    pq.push({ni, nd, nc});
                }
            }
        }
        if(ans == INF) printf("Poor KCM\n");
        else printf("%d\n", ans); 
    }
}