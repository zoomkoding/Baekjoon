#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

vector<pair<float, float> > v;
vector<vector<float> > edge;

int* parent;

int find(int i){
    if(parent[i] == -1) return i;
    return find(parent[i]);
}

void Union(int x, int y){
    int xset = find(x);
    int yset = find(y);
    if(xset != yset) parent[xset] = yset;
}

int isCycle(int src, int dest){
    int x = find(src);
    int y = find(dest);
    if (x == y) return 1;
    Union(x, y);
    return 0;
}

bool compare(vector<float> a, vector<float> b){
    return a[2] < b[2];
}

float find_d(int i, int j){
    return sqrt(pow((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2));
}

int main(){
    int n;
    float x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%f %f", &x, &y);
        v.push_back(make_pair(x, y));
    }
    int edge_N = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            float d = find_d(i, j);
            edge.push_back(vector<float>());
            edge[edge_N].push_back(i);
            edge[edge_N].push_back(j);
            edge[edge_N].push_back(d);
            edge_N ++;
        }
    }
    int count = 0;
    parent = new int[n];
    for(int i = 0 ; i < n; i++) parent[i] = -1;
    sort(edge.begin(), edge.end(), compare);
    
    float answer = 0;
    for(int i = 0; i < edge.size(); i++){
        if(!isCycle((int)edge[i][0], (int)edge[i][1])){
            answer += edge[i][2];
            count ++;
            if(count == n - 1) break;
        }
    }
    printf("%.2f", answer);
    return 0;
}
