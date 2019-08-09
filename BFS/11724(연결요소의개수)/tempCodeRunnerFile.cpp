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

int ans, n, m, u, v, par[1001];

int find(int a){
    if(par[a] == 0)return a;
    return find(par[a]);
}

void Union(int a, int b){
    int A = find(a), B = find(b);
    if(A == B)return;
    par[A] = B;
}

int main(){
    n = readInt(), m = readInt();
    while(m--){
        u = readInt(), v = readInt();
        Union(u, v);
    }
    for(int i = 1; i < n + 1; i++){
        if(par[i] == 0)ans ++;
    }
    printf("%d", ans);

}