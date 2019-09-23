#include <queue>
#include <vector>
#include <cstdio>
#define INF 1000000000

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

vector<vector<int> > ll;
int parent[100020], level[100020];
int n, m, v, w, u;


void build_tree(){
    queue<int> q;
    level[1] = 1, parent[1] = 1;
    q.push(1);
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i];
            if(level[v] == 0){
                level[v] = level[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    n = readInt();    
    ll = vector<vector<int> >(n + 1);
    for(int i = 1; i < n; i++){
        v = readInt(), u = readInt();
        ll[v].push_back(u);
        ll[u].push_back(v);
    }
    build_tree();
    for(int i = 2; i < n + 1; i++)printf("%d\n", parent[i]);
}