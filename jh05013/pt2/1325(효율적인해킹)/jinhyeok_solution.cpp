#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;
void doBFS(vector<vector<int> > arr, int start);
vector<int> result;
vector<int> maxvalue;
int maxcount = 0;
int main(void){
  result.push_back(0);
  maxvalue.push_back(0);
  int vertex_count, edge_count, from, to;

  scanf("%d %d",&vertex_count, &edge_count);
  vector<vector<int> > arr(vertex_count, vector<int>());
  for(int i = 0 ; i<edge_count ; i++){
    scanf("%d %d",&from, &to);
    arr[to - 1].push_back(from);
  }
  // for(int i = 0 ; i<vertex_count ; i++){
  //   cout<<arr[i].size()<<endl;
  // }
  // for(int i = 0 ; i<vertex_count ; i++){
  //   for(int j = 0 ; j<arr[i].size() ; j++)
  //     cout<<i+1<<" "<<arr[i][j];
  //   cout<<endl;
  // }
  // printf("%d",arr[1].size());
  for(int i = 0 ;i<vertex_count;i++)
    doBFS(arr, i+1);
  return 0;
}

void doBFS(vector<vector<int> > arr, int start){
  bool visited[10001] = {0, };
  int count = 0;
  int new_start;
  queue<int> q;
  visited[start-1] = 1;
  q.push(start);
  // cout<<q.empty();
  while(q.empty()==0)
  {
    new_start = q.front(); q.pop();
    for(int i = 0 ; i<arr[new_start-1].size(); i++){
      if(visited[arr[new_start-1][i] - 1]==0){
        visited[arr[new_start-1][i] - 1] = 1;
        q.push(arr[new_start-1][i]);
      }
    }
    count++;
  }
  printf("%d\n",count);
}