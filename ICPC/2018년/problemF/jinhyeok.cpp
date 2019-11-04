#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct data{
  int value;
  int a;
  int b;
};
int main(void){
  int w,c,n[5001],min,max,r=0;
  cin>>w>>c;
  for(int i=0 ;i<c;i++){
    cin>>n[i];
  }
  sort(n,n+c);
  min = n[0]; max = n[c];
  vector<struct data> dp[80000];
  bool check[80000] = {0, };
  for(int i = 0 ;i<c;i++){
        for(int j = i+1;j<c;j++){
            struct data temp;
            temp.value = n[i]+n[j];
            temp.a = n[i];
            temp.b = n[j];
            dp[temp.value].push_back(temp);
            check[temp.value] = 1;
        }
  }
  for(int i = 1 ;i<=w/2;i++){
    if(check[i]==1 && check[w-i]==1){
      for(int j = 0; j<dp[i].size();j++){
        for(int k = 0;k<dp[w-i].size();k++){
          if(((dp[i][j].a != dp[w-i][k].a) && (dp[i][j].b != dp[w-i][k].b)) && ((dp[i][j].a != dp[w-i][k].b) && (dp[i][j].b != dp[w-i][k].a))){r=1; break;}
        }
      }
    }
  }
  if(r==1) cout<<"YES";
  else cout<<"NO";
  return 0;
}