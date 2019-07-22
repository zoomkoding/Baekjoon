#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int m, n, v, w, M;
vector<vector<int> > ll;

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

int bfs(int s){
    int c = 0;
    queue<int> q;
    q.push(s);
    vector<int> visited = vector<int>(n+1, 0);
    visited[s] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i = 0; i < ll[x].size(); i++){
            int y = ll[x][i];
            if(visited[y])continue;
            visited[y] = 1;
            q.push(y);
            c++;
        }
    }
    return c;
}
int main(){
    n = readInt(), m = readInt();
    ll = vector<vector<int> >(n+1);
    vector<int> trust(n+1);
    for(int i = 0 ; i < m; i++){
        v = readInt(), w = readInt();
        ll[w].push_back(v);
    }
    for(int i = 1; i < n + 1; i++){
        trust[i] = bfs(i);
        if(trust[i] > M) M = trust[i];
    }
    for(int i = 1; i < n + 1; i++){
        if(trust[i] == M) printf("%d ", i);
    }
    
}