#include <iostream>
#include <string>

using namespace std;

int main(){
    string line = "";
    while(getline(cin,line)){
      int count[4] = {0,};
      for(int i = 0; i < line.length(); i++){
        if('a' <= line[i] && line[i] <= 'z')count[0] ++;
        else if('A' <= line[i] && line[i] <= 'Z')count[1] ++;
        else if('0' <= line[i] && line[i] <= '9')count[2] ++;
        else if(line[i] == ' ')count[3] ++;
      }
      for(int i = 0; i < 4; i++)cout << count[i] << " ";
      cout << endl;
    }
    return 0;
}