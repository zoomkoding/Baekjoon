#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, input;
    scanf("%d", &n);
    while(n--){
      int sum = 0; float aver;
      scanf("%d", &m);
      vector<int> v(m);
      for(int i = 0; i < m; i++){
        scanf("%d", &v[i]);
        sum += v[i];
      }
      sort(v.begin(), v.end());
      aver = (float)sum / (float)m;
      int up = upper_bound(v.begin(), v.end(), aver) - v.begin();
      printf("%.3f%%\n", 100 - (float)(up)*100/(float)m);
    }
}