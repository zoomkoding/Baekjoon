#include <cstdio>
#include <vector>
#include <queue>
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

typedef struct Point{
    int v, w;
    Point(){}
    Point(int i, int j){
        v = i;
        w = j;
    }
}Point;

struct cmp {
	bool operator()(Point x, Point y) {
		return x.w > y.w;
	}
};

int V, E, K, u, v, w, n;
vector< vector< Point > > ll;

vector<int> djistra(int root){
    vector<int> d(V+1, INF);
    priority_queue<Point, vector<Point>, cmp> pq;
    d[root] = 0; 
    pq.push(Point(root, d[root]));
    while(!pq.empty()){
        u = pq.top().v, w = pq.top().w; pq.pop();
        if(w > d[u]) continue; //weight가 다른 중복이 있을 수 있기 때문에
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].v, w = ll[u][i].w;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(Point(v, d[v]));
            }
        }
    }
    return d;
}

int main(){
    scanf("%d %d %d", &V, &E, &K);
    ll = vector< vector< Point > >(V+1);
    
    for(int i = 0; i < E; i++){
        u = readInt(), v = readInt(), w = readInt();
        ll[u].push_back(Point(v, w));
    }

    vector<int> d = djistra(K);
    
    for(int i = 1; i < d.size() ; i++){
        if(d[i] == INF) printf("INF\n");
        else printf("%d\n", d[i]);
    }
}