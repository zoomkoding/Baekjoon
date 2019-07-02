#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  vector<string> v;
  string s;
  cin >> s;

  int count = s.length();

  for(int i = 0; i < count; i++){
    v.push_back(s);
    s = s.substr(1, count -1 -i);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < count; i++) cout << v[i] << endl;
}