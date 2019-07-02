#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int* in;
queue<int> q;

int main(){
    int N, M, v1, v2;
    scanf("%d %d", &N, &M);
    vector<vector<int> > v;
    for(int i = 0; i <= N; i++)v.push_back(vector<int>());
    in = new int[N+1];
    for(int i = 0; i <= N; i++)in[i] = 0;
    for(int i = 0 ; i < M; i++){
        scanf("%d %d", &v1, &v2);
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