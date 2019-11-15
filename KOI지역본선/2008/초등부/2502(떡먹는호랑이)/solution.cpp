#include <cstdio>
int d, k, arr[2];

void find(int day){
    if(day == 1 || day == 2){
        arr[day - 1] ++;
        return;
    }
    find(day - 1), find(day - 2);
}

int main(){
    scanf("%d %d", &d, &k);
    find(d);
    for(int i = 1; i <= 100000; i++){
        if((k - arr[0] * i) % arr[1] == 0){
            printf("%d\n%d", i, (k - arr[0] * i) / arr[1]);
            break;
        }
    }

}