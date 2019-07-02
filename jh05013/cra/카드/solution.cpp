#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
  map<long long, long long> m;
  long long N, input, max_num = -1, max_count = -1;
  cin >> N;
  
  for(int i = 0 ; i < N; i++){
    cin >> input;
    if(m.find(input)->second == m.end()->second)m[input] = 0;
    else m[input] ++;
    
    if((m[input] > max_count) || (m[input] == max_count && input < max_num) ){
      max_count = m[input];
      max_num = input;
    }
  }
  cout << max_num;
  
}