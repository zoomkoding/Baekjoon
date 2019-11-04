#include <cstdio>

int main(){
    int x[3], y[3];
    for(int i = 0; i < 3; i++) scanf("%d %d", &x[i], &y[i]);
    int s = (x[1] - x[0])*(y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);
    if(s > 0)printf("1");
    else if(s == 0)printf("0");
    else printf("-1");
}