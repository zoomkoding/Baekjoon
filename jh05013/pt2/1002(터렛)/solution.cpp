#include <cstdio>
#include <cmath>
#include <cstdlib>
double sqr(double x){return x*x;}
int main(){
    int t, x1, x2, y1, y2, r1, r2;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double d = sqrt(sqr(x1 - x2) + sqr(y1 - y2));
        if(d == 0 && r1 == r2)printf("-1\n");
        else if(abs(r2 - r1) < d && d < abs(r2 + r1))printf("2\n");
        else if(abs(r2 + r1) == d || abs(r2 - r1) == d)printf("1\n");
        else printf("0\n");
    }
}