#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>

#define INF 1000000000
#define SIZE 50020

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
int ac[SIZE][17], depth[SIZE];
int n, m, v, w, u, max_level, temp, child;

void getTree(int current, int parent){
    depth[current] = depth[parent] + 1;
    ac[current][0] = parent;
    for(int i = 1; i <= max_level; i++){
        temp = ac[current][i-1];
        ac[current][i] = ac[temp][i-1];
    }

    int len = ll[current].size();
    for(int i = 0; i < len; i++){
        int child = ll[current][i];
        if(child != parent) getTree(child, current);
    }
}

int find_LCA(int a, int b){
    int diff = depth[b] - depth[a];
    for(int i = 16; i >= 0; i--){
        if((1<<i) <= diff){
            b = ac[b][i];
            diff -= (1<<i);
        }
    }
    // for(int i = max_level; i >= 0; i--){
    //     if(depth[a] <= depth[ac[b][i]]) b = ac[b][i];
    // }
    if(a == b) return a;
    for(int i = max_level; i >= 0; i--){
        if(ac[a][i] != ac[b][i])a = ac[a][i], b = ac[b][i];
    }
    return ac[a][0];
}

int main(){
    n = readInt();
    ll = vector<vector<int> >(n + 1);
    for(int i = 1; i < n; i++){
        v = readInt(), u = readInt();
        ll[v].push_back(u);
        ll[u].push_back(v);
    }
    depth[0] = -1;
    max_level = (int)floor(log2(SIZE));
    getTree(1, 0);
    m = readInt();
    while(m--){
        v = readInt(), u = readInt();
        printf("%d\n", depth[v] < depth[u] ? find_LCA(v, u) : find_LCA(u, v));
    }
}