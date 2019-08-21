//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/08/22/baekjoon-2263.html

#include <cstdio>

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
int n, temp, post[100001], in[100001];

void pre(int ps, int pd, int is, int id){
    int root = post[pd];
    printf("%d ", root);
    int lcnt = in[root] - is - 1;
    if(in[root] != is) pre(ps, ps + lcnt, is, in[root] - 1);
    if(in[root] != id) pre(ps + lcnt + 1, pd - 1, in[root] + 1, id);
}

int main(){
    n = readInt();
    for(int i = 0; i < n; i++){
        temp = readInt();
        in[temp] = i;
    }
    for(int i = 0; i < n; i++)post[i] = readInt();
    pre(0, n - 1, 0, n - 1);
}