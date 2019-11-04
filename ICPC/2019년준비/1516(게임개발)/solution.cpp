#include <cstdio>
#include <vector>
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
int t, en, n, in[501], w[501], ans[501];
vector<vector<int> > e;
int main(){
    scanf("%d", &n);
    e = vector<vector<int> >(n+1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        while(1){
            scanf("%d", &t);
            if(t == -1)break;
            e[t].push_back(i);
            in[i]++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            if(in[j])continue;
            in[j] = 1;
            ans[j] += w[j];
            en = e[j].size();
            for(int k = 0; k < en; k++){
                int next = e[j][k];
                in[next] --;
                if(ans[next] < ans[j])ans[next] = ans[j];
            }
            break;
        }
    }
    for(int i = 1; i <= n; i++)printf("%d\n", ans[i]);
}