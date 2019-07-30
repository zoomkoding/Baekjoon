#include <cstdio>
#include <vector>
#define INF 1000000

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

int main(){
    int n, e, x, y, w, v1, v2, p1, p2;
    int dist[802][802];
    n = readInt(), e = readInt();
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++)dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for(int i = 0; i < e; i++){
        x = readInt(), y = readInt(), w = readInt();

        dist[x][y] = w;
        dist[y][x] = w;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];   
            }
        }
    }
    v1 = readInt(), v2 = readInt();
    p1 = dist[1][v1] + dist[v1][v2] + dist[v2][n];
    p2 = dist[1][v2] + dist[v2][v1] + dist[v1][n];
    p1 = min(p1, p2);
    printf("%d", p1 > INF ? -1 : p1);
}