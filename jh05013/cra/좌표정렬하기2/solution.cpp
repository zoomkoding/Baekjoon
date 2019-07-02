#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;


int main(){
  vector<pair<int, int>> v;
  int count, n1, n2;
  scanf("%d", &count);

  for(int i = 0; i < count; i++){
    scanf("%d %d", &n1, &n2);
    v.push_back(make_pair(n2, n1));
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < count; i++) printf("%d %d\n", v[i].second, v[i].first);
}