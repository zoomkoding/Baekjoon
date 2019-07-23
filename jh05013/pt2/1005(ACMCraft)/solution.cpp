#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

int t, n, k, v, u, w;

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

int main(){
    t = readInt();
    for(int i = 0; i < t; i++){
        n = readInt(), k = readInt();
        vector<int> build_t(n + 1);
        vector<int> total_t(n + 1, 0);
        vector<int> in(n+1, 0);
        vector< vector<int> > ll(n + 1);
        queue<int> q;
        for(int j = 1; j < n + 1; j++)build_t[j] = readInt();
        for(int j = 0; j < k; j++){
            v = readInt(), u = readInt();
            ll[v].push_back(u);
            in[u] ++;
        }
        w = readInt();
        for(int j = 1; j < n + 1; j++)if(!in[j]) q.push(j);

        while(!q.empty()){
            int front = q.front(); q.pop();
            total_t[front] += build_t[front];
            if(front == w)break;
            for(int j = 0; j < ll[front].size(); j++){
                int dst = ll[front][j];
                in[dst]--;
                if(total_t[dst] < total_t[front])total_t[dst] = total_t[front];
                if(in[dst] == 0)q.push(dst);
            }
        }
        printf("%d\n", total_t[w]);
    }
}