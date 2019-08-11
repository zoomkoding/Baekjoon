#include <cstdio>
using namespace std;

int n, w[303], d[303][2];

int main(){

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    d[1][0] = d[1][1] = w[1];
    d[2][0] = d[2][1] = w[2];
    for(int i = 1; i <= n; i++){
        //이전에 한번 이동한 애에서 두개 뻗치기
        if(d[i][0] + w[i + 2] > d[i + 2][0])d[i + 2][0] = d[i][0] + w[i + 2];
        if(d[i][0] + w[i + 2] > d[i + 2][1])d[i + 2][1] = d[i][0] + w[i + 2];
        //이전에 두개 이동한 애에서는 둘다 가야지
        if(d[i][1] + w[i + 1] > d[i + 1][0])d[i + 1][0] = d[i][1] + w[i + 1]; 
        if(d[i][1] + w[i + 2] > d[i + 2][0])d[i + 2][0] = d[i][1] + w[i + 2];
        if(d[i][1] + w[i + 2] > d[i + 2][1])d[i + 2][1] = d[i][1] + w[i + 2];
    }
    printf("%d", d[n][0] > d[n][1] ? d[n][0] : d[n][1]);
}