//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/07/31/baekjoon-5719.html

#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define X first
#define Y second
#define INF 600000

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

int n, m, s, d, u, v, p, w, sp;

int findsp(vector< vector<pii> > &e, vector< vector<pii> > &r, vector< vector<int> > &block, int del){
    vector<int> dist(n, INF);
    vector<int> prev;
    priority_queue<pii, vector<pii>, greater<pii> >pq; 

    dist[s] = 0;
    pq.push(pii(0, s));
    while(!pq.empty()){
        int top = pq.top().Y, w = pq.top().X; pq.pop();
        for(int i = 0; i < e[top].size(); i++){
            int next = e[top][i].Y, next_w = e[top][i].X;
            if(!block[top][next] && w + next_w <= dist[next]){
                dist[next] = w + next_w;
                pq.push(pii(dist[next], next));
            }
        }
    }
    if(del){
        queue<int> trace;
        trace.push(d);
        while(!trace.empty()){
            int front = trace.front(); trace.pop();
            for(int i = 0; i < r[front].size(); i++){
                int prev = r[front][i].Y, prev_w = r[front][i].X;
                if(dist[front] - prev_w == dist[prev]){
                    trace.push(prev);
                    block[prev][front] = 1;
                }
            }
        }
    }
    return dist[d];
}

int main(){
    while(1){
        n = readInt(), m = readInt();
        if(!n && !m)break;
        s = readInt(), d = readInt();
        vector<vector<pii> > e(n);
        vector<vector<pii> > r(n);
        vector<vector<int> > block(n, vector<int>(n, 0));
        while(m--){
            u = readInt(), v = readInt(), p = readInt();
            e[u].push_back(pii(p, v));
            r[v].push_back(pii(p, u));
        }
        sp = findsp(e, r, block, 1);
        int t = findsp(e, r, block, 0);

        if(t >= INF) printf("-1\n");
        else printf("%d\n", t);
    }
}