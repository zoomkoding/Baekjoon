#include <cstdio>

void matrix_multi(long long ** a, long long** b, long long** c, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long temp = 0;
            for(int k = 0; k < n; k++)temp += a[i][k] * b[k][j];
            c[i][j] = temp % 1000;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = c[i][j];
        }
    }
    
}
int main(){
    long long n, b, input;
    scanf("%lld %lld", &n, &b);
    long long** arr1 = new long long*[n];
    long long** arr2 = new long long*[n];
    long long** result = new long long*[n];
    
    for(int i = 0; i < n; i++){
        arr1[i] = new long long[n];
        arr2[i] = new long long[n];
        result[i] = new long long[n];
    } 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &input);
            arr1[i][j] = arr2[i][j] = input;
        }
    }
    
    for(int i = 1; i < b; i++)matrix_multi(arr1, arr2, result, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)printf("%lld ", arr1[i][j]);
        printf("\n");
    }
    
}