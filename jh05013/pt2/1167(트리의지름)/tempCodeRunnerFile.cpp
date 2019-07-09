#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

queue<int> q;
vector<vector<pair<int,int> > > v;
int max = 0;
int n;

void dfs(int src, int d, int parent){
  bool exist = false;
  for(int i = 0; i < v[src].size(); i++){
      if(v[src][i].first == parent) continue;
      exist = true;
      dfs(v[src][i].first, d + v[src][i].second, src);
  }
  if(!exist && max < d)max_d = d;
}

int main(){
    
    scanf("%d", &n);
    for(int i = 0; i < n + 1; i++)v.push_back(vector<pair<int,int> >());
    for(int i = 0; i < n; i++){
        int n1, n2, w;
        scanf("%d", &n1);
        while(1){
            scanf("%d", &n2);
            if(n2 == -1) break;
            scanf("%d", &w);
            v[n1].push_back(make_pair(n2,w));
        }
    }
    for(int i = 1; i <= n; i++){
        if(v[i].size() == 1) dfs(i, 0, 0);
    }
    printf("%d", max);
    
}
