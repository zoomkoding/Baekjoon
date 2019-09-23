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

int n, m, n1, n2, answer;
int* visited;
vector<vector<int> > v;
queue<int> q;

int main(){
    n =readInt(), m = readInt();
    visited = new int[n+1];
    for(int i = 0; i <= n; i++){
        v.push_back(vector<int>());
        visited[i] = 0;
    }
    
    while(m--){
        n1 = readInt(), n2 = readInt();
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        answer ++;
        for(int i = 0; i < v[temp].size(); i++){
            if(!visited[v[temp][i]]) {
                q.push(v[temp][i]);
                visited[v[temp][i]] = 1;
            }
        }
    }
    printf("%d", answer-1);
}