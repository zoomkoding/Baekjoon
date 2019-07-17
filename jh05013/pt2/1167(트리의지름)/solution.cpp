#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#define INF 1000000000

using namespace std;

typedef struct Point{
    int v, w;
    Point(){}
    Point(int i, int j){
        v = i;
        w = j;
    }
}Point;

queue<int> q;
vector< vector< Point > > ll;
int n, v, w, u;

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

Point find_d(int root){
    int max_i = 1;
    vector<int> d(n+1, INF);
    queue<int> q;
    d[root] = 0; 
    q.push(root);
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].v, w = ll[u][i].w;
            if(d[v] != INF)continue;
            d[v] = d[u] + w;
            q.push(v);
        }
    }
    for(int i = 1; i < d.size(); i++){
        if(d[max_i] < d[i])max_i = i;
    }
    return Point(max_i, d[max_i]);
}


int main(){
    n = readInt();
    ll = vector< vector< Point > >(n+1);
    for(int i = 0; i < n; i++){
        int n1, n2, w;
        n1 = readInt();
        while(1){
            n2 = readInt();
            if(n2 == -1) break;
            w = readInt();
            ll[n1].push_back(Point(n2,w));
        }
    }
    printf("%d", find_d(find_d(1).v).w);
}
