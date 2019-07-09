#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, m, answer;
  int best_p = 1000, best_l = 1000;
  int p, l;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> p >> l;
    if(p < best_p) best_p = p;
    if(l < best_l) best_l = l;
  }
  answer = n * best_l;
  int price_l = best_p * (n/6) + best_l * (n%6);
  int price_p = best_p * (n/6 + 1); 
  if(price_l < answer) answer = price_l;
  if(price_p < answer) answer = price_p;
  cout << answer;
}
