#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
  int n, temp;
  int num = 0, answer = 0;
  vector<int> v;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    num += v[i];
    answer += num;
  }
  
  cout << answer << endl;
}
