#include <cstdio>
#include <vector>
#include <queue>
#define INF 10000000
#define pii pair<int, int>
using namespace std;

namespace fio {
	const int BS = 524288;
	char buf[BS];
	char *p = buf + BS;
	inline char readChar() {
		if (p == buf + BS) {
			fread(buf, 1, BS, stdin);
			p = buf;
		}
		return *p++;
	}
	int readInt() {
		char c = readChar();
		while (c < '0') c = readChar();
		int ret = 0;
		while (c >= '0')ret = ret * 10 + c - '0', c = readChar();
		return ret;
	}
}



int V, E, K, u, v, w, n;
vector< vector< pii > > ll;
struct cmp{
    bool operator()(pii p1, pii p2){
        return p1.first < p2.first;
    }
};
int main(){
    scanf("%d %d %d", &V, &E, &K);
    ll = vector< vector< pii > >(V+1);
    for(int i = 0; i < E; i++){
        u = fio::readInt(), v = fio::readInt(), w = fio::readInt();
        ll[u].push_back(pii(v, w));
    }

    vector<int> d(V+1, INF);
    priority_queue<pii, vector<pii>, cmp> pq;
    d[K] = 0; 
    pq.push(pii(0, K));
    while(!pq.empty()){
        pii top = pq.top();
        w = top.first, u = top.second; pq.pop();
        if(w > d[u]) continue; //weight가 다른 중복이 있을 수 있기 때문에
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].first, w = ll[u][i].second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(pii(d[v], v));
            }
        }
    }
    for(int i = 1; i < d.size() ; i++){
        if(d[i] == INF) printf("INF\n");
        else printf("%d\n", d[i]);
    }
}