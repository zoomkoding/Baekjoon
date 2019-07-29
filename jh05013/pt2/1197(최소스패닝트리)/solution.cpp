#include <cstdio>
#include <vector>
#include <algorithm>

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

vector<vector<int> > edges;
int parent[10001];

int find(int i){
    if(parent[i] == 0) return i;
    return parent[i] = find(parent[i]);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int main(){
    int v, e;
    v = readInt(), e = readInt();
    edges= vector< vector<int> >(e, vector<int>(3));
    for(int i = 0; i < e; i ++)edges[i][0] = readInt(), edges[i][1] = readInt(), edges[i][2] = readInt();

    int answer = 0;
    
    sort(edges.begin(), edges.end(), compare);

    for(int i = 0; i < edges.size(); i++){
        if(find(edges[i][0]) == find(edges[i][1]))continue;
        answer += edges[i][2];
        Union(edges[i][0], edges[i][1]);
    }

    printf("%d", answer);
}