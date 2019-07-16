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
int visited[26][26] = {0, };
int savecount[635] = {0, };
void doBFS(char arr[][26], int visited[][26], queue<struct xy> q, int x_size, int y_size, int count);
int main(void){
  char map[26][26];
  int size, input;
  int count = 0;
  queue<struct xy> q;
  scanf("%d",&size);
  getchar();
  for(int i = 0; i<size;i++){
    for(int j= 0 ; j<size;j++){
      scanf("%c",&map[i][j]);
    }
    getchar();
  }
  for(int i = 0; i<size;i++){
    for(int j= 0 ; j<size;j++){

      if(map[i][j] == 49 && visited[i][j] == 0){
        visited[i][j] = 1;
        struct xy temp;
        temp.x = j;
        temp.y = i;
        q.push(temp);
        count++;
        doBFS(map, visited, q, size, size, count);
        q.pop();
      }
    }
  }
  cout<<count<<"\n";
  sort(savecount,savecount+count);
  for(int i = 0; savecount[i] != 0 ;i++) cout<<savecount[i]<<"\n";
  return 0;
}
void doBFS(char arr[][26], int visited[][26], queue<struct xy> q, int x_size, int y_size, int count){
  int apartcount = 0;
  while(q.empty()==0)
  {
    struct xy temp = q.front();
    struct xy temp2;
    visited[temp.y][temp.x] = 1;
    arr[temp.y][temp.x] = count+48;
    if(arr[temp.y][temp.x-1] == 49 && visited[temp.y][temp.x-1] == 0 && temp.x>0){
      temp2.x = temp.x - 1;
      temp2.y = temp.y;
      arr[temp.y][temp.x-1] = count+48;
      visited[temp.y][temp.x-1] = 1;
      q.push(temp2);
    }
    if(arr[temp.y][temp.x+1] == 49 && visited[temp.y][temp.x+1] == 0 && temp.x + 1<x_size){
      temp2.x = temp.x + 1;
      temp2.y = temp.y;
      arr[temp.y][temp.x+1] = count+48;
      visited[temp.y][temp.x+1] = 1;
      q.push(temp2);
    }
    if(arr[temp.y-1][temp.x] == 49 && visited[temp.y-1][temp.x] == 0 && temp.y>0){
      temp2.y = temp.y - 1;
      temp2.x = temp.x;
      arr[temp.y-1][temp.x] = count+48;
      visited[temp.y-1][temp.x] = 1;
      q.push(temp2);
    }
    if(arr[temp.y+1][temp.x] == 49 && visited[temp.y+1][temp.x] == 0 && temp.y + 1<y_size){
      temp2.y = temp.y + 1;
      temp2.x = temp.x;
      arr[temp.y+1][temp.x] = count+48;
      visited[temp.y+1][temp.x] = 1;
      q.push(temp2);
    }
    apartcount++;
    q.pop();
  }
  savecount[count-1] = apartcount;
}