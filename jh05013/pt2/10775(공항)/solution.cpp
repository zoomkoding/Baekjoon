//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/09/23/baekjoon-10775.html

#include <iostream>
using namespace std;

int par[500001], g, p, x, ans;

int find(int i){
    if(par[i] == i)return i;
    return par[i] = find(par[i]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> g >> p;
    for(int i = 0; i < g + 1; i++)par[i] = i;
    for(int i = 0; i < p; i++){
        cin >> x;
        int px = find(x);
        if(!px)break;
        //Union
        par[px] = find(px - 1);
        ans ++;
    }
    cout << ans;
}