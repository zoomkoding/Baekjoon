//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/07/31/baekjoon-9370.html

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int, int>
#define FOR(i,j) for(int i = 0; i < j; i++)

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
inline int N() {
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

int main(){
    int T, n, m, t, s, g, h, a, b, w, x;
    T = N();
    while(T--){
        n = N(), m = N(), t = N(), s = N(), g = N(), h = N();
        vector<vector<pii> > e(n + 1);
        while(m--){
            a = N(), b = N(), w = N();
            e[a].push_back({b, w});
            e[b].push_back({a, w});
        }
        vector<int> d;
        vector<int> to_g(n + 1);
        vector<int> to_h(n + 1);
        queue<int> q;        
        for(int i = 0; i < 3; i++){
            d = vector<int>(n+1, 20000000);
            if(i == 0) a = g;
            else if(i == 1) a = h;
            else a = s;
            d[a] = 0;
            q.push(a);
            while(!q.empty()){
                int top = q.front(); q.pop();
                FOR(i, e[top].size()){
                    int next = e[top][i].first, w = e[top][i].second;
                    if(d[next] > d[top] + w){
                        d[next] = d[top] + w;
                        q.push(next);
                    }
                }
            }
            if(i == 0)FOR(j, n + 1)to_g[j] = d[j];
            else if(i == 1)FOR(j, n + 1)to_h[j] = d[j];            
        }
        vector<int> ans;
        while(t--){
            x = N();
            if(to_g[s] + to_g[h] + to_h[x] == d[x]) ans.push_back(x);
            else if(to_h[s] + to_g[h] + to_g[x] == d[x]) ans.push_back(x);
        }
        sort(ans.begin(), ans.end());
        FOR(i, ans.size())printf("%d ", ans[i]);
        printf("\n");
    }
}
