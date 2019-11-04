#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;
namespace fio {
	const int BSIZE = 524288;
	char buffer[BSIZE];
	char *p = buffer + BSIZE;
	inline char readChar() {
		if (p == buffer + BSIZE) {
			fread(buffer, 1, BSIZE, stdin);
			p = buffer;
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
int ans, n, m, v1, v2, w, src, dst, visited[100001];
vector<vector<pii> > e;
int bfs(int c){
    for(int i = 0; i < n + 1; i++)visited[i] = 0;
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty()){
        int front = q.front(), fc = e[front].size(); q.pop();
        if(front == dst)return 1;
        for(int i = 0; i < fc; i++){
            pii next = e[front][i];
            int nw = next.first, nx = next.second;
            if(nw < c || visited[nx]) continue;
            visited[nx] = 1;
            q.push(nx);
        }
    }
    return 0;
}

int main(){
    int l = 1, r = 0;
    n = fio::readInt(); m = fio::readInt();
    e = vector<vector<pii> >(n+1);
    for(int i = 0; i < m; i++){
        v1 = fio::readInt(); v2 = fio::readInt(); w = fio::readInt();
        if(w > r) r = w;
        e[v1].push_back(pii(w, v2));
        e[v2].push_back(pii(w, v1));
    }
    src = fio::readInt(); dst = fio::readInt();
    while(l <= r){
        int mid = (l + r) / 2;
        int result =  bfs(mid);
        //성공시 높혀, ans는 여기야
        if(result)l = mid + 1, ans = mid;
        //실패시 낮춰
        else r = mid - 1;
    }
    printf("%d", ans);
}