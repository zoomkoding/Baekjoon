#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  vector<int> answers;
  int t, n, g1, g2;
  vector<pair<int, int>> v;

  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> n;
    v.clear();
    int g2_max = 100000, answer = 0;

    for(int j = 0; j < n; j++){
      cin >> g1 >> g2;
      v.push_back(make_pair(g1, g2));
    }

    sort(v.begin(), v.end());

    for(int j = 0; j < n; j++){
      if(v[j].second <= g2_max){
        g2_max = v[j].second;
        answer ++;
      }
    }
    answers.push_back(answer);
  }
  for(int i = 0; i < answers.size(); i++)cout << answers[i]<<endl;
}
