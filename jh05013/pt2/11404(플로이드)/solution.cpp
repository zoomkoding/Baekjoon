//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/08/07/baekjoon-11404.html

#include <cstdio>
#define INF 987654321
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
    int d[101][101];
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++)d[i][j] = INF;
        d[i][i] = 0;
    }
    while(m--){
        scanf("%d %d %d", &u, &v, &w);
        if(d[u][v] > w)d[u][v] = w;
    }
    for(int k = 1; k < n + 1; k++){
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(d[i][j] > d[i][k] + d[k][j])d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(d[i][j] == INF)printf("0 ");
            else printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}