//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/09/26/baekjoon-1693.html

#include <cstdio>
#include <vector>
#include <cmath>

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

int n, cnt, v1, v2, visited[100001];
int dp[100001][16];
vector< vector<int> > e;
void find(int x){
    int c = e[x].size();
    for(int i = 0; i < c; i++){
        int nx = e[x][i];
        if(visited[nx])continue;
        visited[nx] = 1;
        find(nx);
        for(int j = 1; j < cnt; j++){
            int m = 987654321, mi = 0;
            for(int k = 1; k < cnt; k++){
                if(j == k)continue;
                if(m > dp[nx][k])m = dp[nx][k], mi = k;
            }
            dp[x][j] += m;
        }
    }
    for(int i = 1; i < cnt; i++)dp[x][i] += i;
    return;
}

int main(){
    n = readInt();
    cnt = log2(n) + 1;
    e = vector< vector<int> >(n + 1);
    for(int i = 0; i < n - 1; i++){
        v1 = readInt(), v2 = readInt();
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    visited[1] = 1;
    find(1);
    int ans = 987654321;
    for(int i = 1; i < cnt; i++){
        if(ans > dp[1][i])ans = dp[1][i];
    }
    printf("%d", ans);
}