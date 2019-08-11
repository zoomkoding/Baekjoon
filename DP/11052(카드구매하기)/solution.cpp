#include <cstdio>

int n, p[10001];

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n + 1; i++) scanf("%d", &p[i]);
    for(int i = 2; i < n + 1; i++){
        for(int j = 1; j < i; j++){
            if(p[j] + p[i-j] > p[i])p[i] = p[j] + p[i-j];
        }
    }
    printf("%d", p[n]);
}

//해당 카드 개수를 사기 위해 필요한 맥스값을 찾아주고 순서대로 업데이트해간다.
