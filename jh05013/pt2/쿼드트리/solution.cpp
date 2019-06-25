#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char** arr;

string divide(int n, int startx, int starty){
  if(n == 1) {
    string x = "";
    x+=arr[startx][starty];
    return x;
  }
  string s = divide(n/2, startx, starty) + divide(n/2, startx, starty + n/2) + divide(n/2, startx + n/2, starty) + divide(n/2, startx+n/2, starty+n/2);
  if(s.compare("1111") == 0 ) return "1";
  else if(s.compare("0000") == 0) return "0";
  else return "(" + s + ")";
  
}

int main() {
  int N;
  string line;
  cin >> N;
  arr = new char*[N];
  for(int i = 0; i < N; i++)arr[i] = new char[N];
  for(int i = 0; i < N; i++){
    cin >> line;
    for(int j = 0; j < N; j++){
      arr[i][j] = line[j];
    }
  }
  cout << divide(N, 0, 0) << endl;
}
