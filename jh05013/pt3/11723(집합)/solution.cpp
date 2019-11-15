#include <cstdio>
int n, temp, check[21];
char c[10];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", c);
        if(c[0] == 'a' && c[1] == 'l'){
            for(int i = 0; i < 21; i++)check[i] = 1;
        }
        else if(c[0] == 'a' && c[1] == 'd'){
            scanf("%d", &temp);
            check[temp] = 1;
        }
        else if(c[0] == 'r'){
            scanf("%d", &temp);
            check[temp] = 0;
        }
        else if(c[0] == 'c'){
            scanf("%d", &temp);
            if(check[temp])printf("1\n");
            else printf("0\n");
        }
        else if(c[0] == 't'){
            scanf("%d", &temp);
            check[temp] = !check[temp];
        }
        else{
            for(int i = 0; i < 21; i++)check[i] = 0;
        }
    }
}