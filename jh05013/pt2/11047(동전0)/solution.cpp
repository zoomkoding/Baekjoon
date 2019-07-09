#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
  int n , k , temp;
  int num = 0, answer = 0;
  vector<int> v;
  cin >> n >> k;

  for(int i = 0; i < n; i++){
    cin >> temp;
    v.push_back(temp);
  }
  for(int i = n - 1; i >= 0; i--){
    if(k == 0) break;
    if(v[i] <= k){
      answer += k / v[i];
      k %= v[i];
    }
  }

  cout << answer << endl;
}
