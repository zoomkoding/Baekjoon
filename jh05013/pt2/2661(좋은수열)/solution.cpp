#include <cstdio>

int n, num[81];

int comp(int a, int b){
    int i = a, j = b;
    while(i < b){
        if(num[i] != num[j]) return 1;
        i++, j++;
    }
    return 0;
}

int make_num(int index){
    if(index == n) {
        for(int i = 0; i < n; i++)printf("%d", num[i]);
        printf("\n");
        return 1;
    }
    int succeed = 0, t = (index + 1) / 2;
    for(int i = 1; i < 4; i++){
        num[index] = i;
        for(int j = 1; j <= t; j++){
            if(!comp(index - j * 2 + 1, index - j + 1)){
                num[index] = 0;
                break;
            }
        }
        if(num[index]!= 0)succeed = make_num(index+1);
        if(succeed) return succeed;
    }
    return 0;
}
int main(){
    scanf("%d", &n);
    make_num(0);
}