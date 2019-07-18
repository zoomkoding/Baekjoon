//일단 edge를 다 받아
//받고 나서 트리를 만들어
    //1번 원소를 큐에 넣어
    //큐에 원소가 없을때까지 반복해
        //원소를 꺼내고 인접 원소의 값을 업데이트해줘
            //root로부터의 거리를 기록하고 
            //parent와 level을 기록해줘
            //parent가 0이면 넣어
//input이 들어오면 up해주고
//두점의 부모가 같아질때까지 올려
//두점으로부터 1번 원소까지 거리를 더하고 공통부모로부터 1번까지의 곱하기 2를 빼줘.

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

vector< vector< Point > > ll;
int parent[17][40020], level[40020], d[40020];
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
    for(int i = 0; i < 17; i++){
        if(parent[i][chd] == parent[i][par]){
            chd = parent[i][chd];
            par = parent[i][par];
        } 
    } 
    return parent[0][chd];
}

void build_tree(){
    queue<int> q;
    level[1] = 1, d[1] = 0, parent[0][1] = 1;
    q.push(1);
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].v;
            if(level[v] == 0){
                level[v] = level[u] + 1;
                parent[0][v] = u;
                d[v] = d[u] + ll[u][i].w;
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
    // n = readInt();
    scanf("%d", &n);
    
    ll = vector< vector< Point > >(n + 1);
    for(int i = 1; i < n; i++){
        // v = readInt(), u = readInt(), w = readInt();
        scanf("%d %d %d", &v, &u, &w);
        ll[v].push_back(Point(u, w));
        ll[u].push_back(Point(v, w));
    }
    build_tree();
    find_parent();

    // m = readInt();
    scanf("%d", &m);
    while(m--){
        // v = readInt(), u = readInt();
        scanf("%d %d", &v, &u);
        printf("%d\n", d[v] + d[u] - d[level[v] > level[u] ? LCA(v, u) : LCA(u, v)]*2);       
    }
}