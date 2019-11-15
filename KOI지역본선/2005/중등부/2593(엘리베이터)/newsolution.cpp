#include <cstdio>
#include <queue>
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
int src = 987654321, n, m, X[101], Y[101], A, B, d[100001], pre_e[100001], pre_f[100001];
vector<int> trace;
void find(){
    queue<int> q;
    q.push(A);
    d[A] = 0;
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(int i = 0; i < m; i++){
            if(front - X[i] < 0)continue;
            if((front - X[i]) % Y[i] != 0)continue;
            for(int j = X[i]; j <= n; j+= Y[i]){
                if(d[j] != -1)continue;
                d[j] = d[front] + 1;
                pre_e[j] = i + 1, pre_f[j] = front;                
                if(j == B)return;
                q.push(j);
            }
        }
    }
}

void find_pre(int x){
    if(x == A)return;
    trace.push_back(pre_e[x]);
    find_pre(pre_f[x]);
}

int main(){
    n = fio::readInt(), m = fio::readInt();
    for(int i = 1; i <= n; i++)d[i] = -1;
    for(int i = 0; i < m; i++){
        X[i] = fio::readInt(), Y[i] = fio::readInt();
        if(src > X[i])src = X[i];
    }
    A = fio::readInt(), B = fio::readInt();
    if(src > B){
        printf("-1");
        return 0;
    }
    find();
    printf("%d\n", d[B]);
    if(d[B] != -1)find_pre(B);
    for(int i = trace.size() - 1; i >= 0; i--)printf("%d\n", trace[i]);
}