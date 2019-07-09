#include <iostream>
#include <string>

using namespace std;

int main(){
  string line = "";
  getline(cin,line);
  
  for(int i = 0; i < line.length(); i++){
    if(line[i] == ' ' || ('0' <= line[i] && line[i] <= '9')) continue;
    if(('a' <= line[i] && line[i] <= 'm') || ('A' <= line[i] && line[i] <= 'M')) line[i] += 13;
    else if('n' <= line[i] && line[i] <= 'z') line[i] = 'a' + (line[i] + 12 - 'z');
    else if('N' <= line[i] && line[i] <= 'Z') line[i] = 'A' + (line[i] + 12 - 'Z'); 
  }
  
  cout << line << endl;
  return 0;
}