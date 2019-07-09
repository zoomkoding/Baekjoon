#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
  int N, input;
  string s[10001];
  int arr[10001] = {0,};
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &input);
    arr[input] ++;
  }
  for(int i = 0; i < 10001; i++){
    for(int j = 0; j < arr[i]; j++)printf("%d\n", i);
  }
}
