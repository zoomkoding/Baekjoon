#include <cstdio>
#include <queue>
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

int* in;
queue<int> q;

int main(){
    int N, M, v1, v2;
    N = readInt(), M = readInt();
    vector< vector<int> > v;
    for(int i = 0; i <= N; i++)v.push_back(vector<int>());
    in = new int[N+1];
    for(int i = 0; i <= N; i++)in[i] = 0;
    for(int i = 0 ; i < M; i++){
        v1 = readInt(), v2 = readInt();
        v[v1].push_back(v2);
        in[v2] ++;
    }
    for(int i = 1; i <N+1; i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int temp = q.front();
        printf("%d ", temp);
        q.pop();
        for(int i = 0; i < v[temp].size(); i++){
            if(--in[v[temp][i]] == 0)q.push(v[temp][i]);
        }
    }    
}