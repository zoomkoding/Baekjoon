#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  unsigned long long answer = 1;
  unsigned long long A, X;
  vector<unsigned long long> v1, v2;
  cin >> A >> X;
  A %= 1000000007;
  while(X != 0){
    if(X%2 == 0) v1.push_back(0);
    else v1.push_back(1);
    X/=2;
  }
  v2.push_back(A);
  for(int i = 1; i < v1.size(); i++){
    unsigned long long temp = (v2[i-1]*v2[i-1])%1000000007;
    v2.push_back(temp);
  }

  for(int i = 0; i < v1.size(); i++){
    if(v1[i] == 1){
      answer *= v2[i]; 
      answer %= 1000000007;
    }
  }
  cout << answer;
}