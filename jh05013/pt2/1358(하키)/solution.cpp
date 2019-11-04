#include <cstdio>
int w, h, r, x, y, p, ans, px, py;
int main(){
    scanf("%d %d %d %d %d", &w, &h, &x, &y, &p);
    r = h / 2;
    while(p--){
        scanf("%d %d", &px, &py);
        if(px >= x && px <= x + w && py >= y && py <= y + h)ans++;
        else if(r * r >= (px - x)*(px - x) + (py - y - r) * (py - y - r))ans++;
        else if(r * r >= (x + w - px)*(x + w - px) + (y + r - py) * (y + r - py))ans++;
    }
    printf("%d", ans);
}