//풀이는 아래 블로그를 참고해주세요!
//https://zoomkoding.github.io/algorithm/2019/09/16/KMP.html

#include <iostream>
using namespace std;

char t[1000001], p[1000001];
int ans[1000001], pi[1000001], an;

void make_pi(){
    int j = 0;
    for(int i = 1; p[i] != '\0' ; i++){
        while(j > 0 && p[i] != p[j]) j = pi[j-1]; 
        if(p[i] == p[j]) pi[i] = ++j; 
    }
}

void do_KMP(){
    int j = 0;
    for(int i = 0; t[i] != '\0'; i++){
        while(t[i] != p[j] && j > 0)j = pi[j - 1];
        if(t[i] == p[j])j++;
        if(p[j] == '\0')ans[an++] = i - j + 2;
    }
}

int main(){
    cin.getline(t, 1000001);
    cin.getline(p, 1000001);
    make_pi();
    do_KMP();
    cout << an << '\n';
    for(int i = 0; i < an; i++)cout << ans[i] << ' ';
}