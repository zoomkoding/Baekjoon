#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstdio>

using namespace std;
struct xy{
  int x;
  int y;
};
int d[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}}; //우,하,상,좌
int depth[101][101];
void doBFS(char arr[][101], int visited[][101], int x_size, int y_size);
int main(void){
  char map[101][101];
  int visited[101][101];
  int y, x;
  scanf("%d %d",&y,&x);
  depth[0][0] = 1;
  getchar();
  for(int i = 0; i<y ;i++){
    for(int j = 0;j<x;j++)
      scanf("%c",&map[i][j]);
    getchar();
  }
  // printf("%d %d %d",map[0][0],map[0][1],map[1][0]);
  doBFS(map, visited, x, y);
  cout<<depth[y-1][x-1];

  return 0;
}
void doBFS(char arr[][101], int visited[][101], int x_size, int y_size){
  queue<struct xy> q;
  struct xy start;
  start.x = 0;
  start.y = 0;
  q.push(start);
  while(q.empty()==0)
  {
    struct xy temp = q.front();
    q.pop();
    
    for(int i= 0;i<4;i++){
      int new_x = temp.x + d[i][0], new_y = temp.y + d[i][1];
      if(new_x>=0 && new_x<x_size && new_y>=0 && new_y<y_size && arr[new_y][new_x]==49 && depth[new_y][new_x] == 0){
        if(new_x == 0 && new_y == 0)continue;
        struct xy temp2;
        temp2.x = new_x; temp2.y = new_y;
        q.push(temp2);
        depth[new_y][new_x] = depth[temp.y][temp.x] + 1;
      }
    }
  }
}