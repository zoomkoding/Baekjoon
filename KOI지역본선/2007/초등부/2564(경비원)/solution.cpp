#include <cstdio>
int sum, cycle, n, m, s, d, temp, arr[101];
int abs(int x){
    if(x > 0)return x;
    else return -x;
}
int count(int x, int y){
    int v1 = x - y, v2 = cycle - v1;
    return v1 < v2 ? v1 : v2;
}
int main(){
    scanf("%d %d", &n, &m);
    scanf("%d", &s);
    for(int i = 0; i < s + 1; i++){
        scanf("%d %d", &d, &temp);
        if(d == 1)arr[i] = temp;
        else if(d == 2)arr[i] = n + m + n - temp;
        else if(d == 3)arr[i] = n + n + m + m - temp; 
        else arr[i] = n + temp;
    }
    cycle = n + n + m + m;
    for(int i = 0; i < s; i++)sum += arr[i] > arr[s] ? count(arr[i], arr[s]) : count(arr[s], arr[i]);
    printf("%d", sum);
}