//풀이는 아래 블로그를 참고해주세요!
//https://zoomkoding.github.io/algorithm/2019/09/16/KMP.html

#include <iostream>
#include <string.h>
using namespace std;

char t[1000001], p[1000001];
int k, tn, pi[1000001];

int do_KMP(){
    int j = 0;
    for(int i = 0; i < tn; i++){
        while(t[i] != p[j] && j > 0)j = pi[j - 1];
        if(t[i] == p[j])j++;
        else return 0;
        if(p[j] == '\0')j = 0;
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    while(1){
        cin >> t;
        if(t[0] == '.' && t[1] == '\0')break;
        tn = strlen(t);
        int j = 0;
        for(int i = 1; i <= tn; i++){
            while(j > 0 && t[i] != t[j]) j = pi[j-1]; 
            if(t[i] == t[j]) pi[i] = ++j; 
            p[i - 1] = t[i - 1], p[i] = '\0';
            if(!(tn % i) && do_KMP()){
                cout << tn / i << '\n';
                break;
            }
        }
    }    
}