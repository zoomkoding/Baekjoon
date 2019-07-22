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
int parent[17][100020], level[100020];
int n, m, v, w, u;

int LCA(int chd, int par){
    int diff = level[chd] - level[par];
    for(int i = 16; i >= 0; i--){
        if((1<<i) <= diff){
            chd = parent[i][chd];
            diff -= (1<<i);
        }
    }
    if(chd == par) return chd;
    for(int i = 16; i >= 0; i--){
        if(parent[i][chd] != parent[i][par]){
            chd = parent[i][chd];
            par = parent[i][par];
        } 
    } 
    return parent[0][chd];
}

void build_tree(){
    queue<int> q;
    level[1] = 1, parent[0][1] = 1;
    q.push(1);
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i];
            if(level[v] == 0){
                level[v] = level[u] + 1;
                parent[0][v] = u;
                q.push(v);
            }
        }
    }
}
void find_parent(){
    for(int i = 1; i < 17; i++){
        for(int j = 1; j < n + 1; j++)parent[i][j] = parent[i-1][parent[i-1][j]];
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
    find_parent();

    m = readInt();
    while(m--){
        v = readInt(), u = readInt();
        printf("%d\n", level[v] > level[u] ? LCA(v, u) : LCA(u, v));       
    }
}