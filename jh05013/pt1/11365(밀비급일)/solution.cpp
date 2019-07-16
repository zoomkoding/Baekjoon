#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        if(s.compare("END") == 0) break;
        for(int i = s.length()-1; i >= 0; i--)printf("%c", s[i]);
        printf("\n");
    }
}