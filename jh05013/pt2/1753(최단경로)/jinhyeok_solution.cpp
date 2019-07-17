// #include<iostream>
// #include<cstdlib>
#include<algorithm>
// #include<vector>
// #include<string>
// #include<stack>
#include<queue>
#include<cstdio>
// #include<windows.h>
using namespace std;
#define MAX 10000000

struct fromtoweight{
  int from;
  int to;
  int weight;
};
struct cmp{
    bool operator()(fromtoweight t, fromtoweight u){
        return t.weight > u.weight;
    }
};
void doDijkstra(struct fromtoweight arr[30001], int vertex_distance[20001], int start_vertex, int edge_count, int vertex_count);
bool cmp(struct fromtoweight a, struct fromtoweight b);
int main(void){
  int vertex_count, edge_count, start_vertex;
  struct fromtoweight arr[30001];
  int vertex_distance[20001];
  scanf("%d %d %d",&vertex_count,&edge_count, &start_vertex);
  for (int i=0 ; i<vertex_count;i++)
    vertex_distance[i] = MAX;
  for(int i = 0 ; i < edge_count ; i++)
    scanf("%d %d %d",&arr[i].from,&arr[i].to,&arr[i].weight);
  vertex_distance[start_vertex-1] = 0;
  sort(arr, arr+edge_count, cmp);
  // for(int i = 0 ;i<edge_count;i++)
  //   printf("%d", arr[i].from);
  doDijkstra(arr, vertex_distance, start_vertex, edge_count, vertex_count);
  for(int i = 0 ; i<vertex_count;i++){
    if(vertex_distance[i]==MAX)
      printf("INF\n");
    else
      printf("%d\n",vertex_distance[i]);
  }


  return 0;
}

void doDijkstra(struct fromtoweight arr[30001], int vertex_distance[20001], int start_vertex, int edge_count, int vertex_count){
  priority_queue<struct fromtoweight, vector<struct fromtoweight>, struct cmp> pq;
  auto searchLB = [](fromtoweight a, int b) -> bool {
    return a.from < b;
  };
  auto searchUB = [](int a, fromtoweight b) -> bool {
    return a < b.from;
  };
  struct fromtoweight temp;
  for(int i = 0 ; i<vertex_count ;i++){
    if(i==start_vertex - 1){
        temp.from = start_vertex;
        temp.to = start_vertex;
        temp.weight = 0;
        pq.push(temp);
    }
    else{
        temp.from = i+1;
        temp.weight = MAX;
        temp.to = i+1;
        pq.push(temp);
    }

  }



  // printf("\n%d\n", pq.size());
  while(pq.empty()==0){
    temp = pq.top();
    vertex_distance[temp.to - 1] = min(vertex_distance[temp.to - 1], vertex_distance[temp.from - 1] + temp.weight);
    pq.pop();
    printf("new vertex: %d \n", temp.to);
    if(temp.weight <= vertex_distance[temp.to - 1]){
        int lb = lower_bound(&arr[0],&arr[edge_count-1], temp.to ,searchLB) - &arr[0];
        int ub = upper_bound(&arr[0],&arr[edge_count-1], temp.to ,searchUB) - &arr[0];
        // printf(" %d %d", lb, ub);
        for(int i = lb ; i<ub ; i++){
            struct fromtoweight temp2 = arr[i];
            pq.push(temp2);
            for(int j = 0 ; j < vertex_count ; j++) printf(" %d ",vertex_distance[j]);
            printf("\n");
        }
    }


  }

}

bool cmp(struct fromtoweight a, struct fromtoweight b) {return a.from<b.from;}