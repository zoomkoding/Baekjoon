#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

 vector<vector<int> >multi(vector<vector<int> > a, vector<vector<int> > b, int n){
    vector<vector<int> > c(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += (long long)a[i][k] * b[k][j];
                c[i][j] %= 1000;
            }
        }
    }
    return c;
}

vector<vector<int> > pow(vector<vector<int> > A, int m, int n){
    vector<vector<int> > half(n, vector<int>(n));
    if(m == 0) return half;
    if(m % 2 > 0) return multi(pow(A, m-1, n), A, n);
    half = pow(A, m/2, n);
    return multi(half, half, n);
}

int main(){
    long long n, b, input;
    scanf("%lld %lld", &n, &b);
    vector<vector<int> > mat1(n, vector<int>(n));


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &input);
            mat1[i][j] = input;
        }
    }
   
    mat1 = pow(mat1, b, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)printf("%d ", mat1[i][j]);
        printf("\n");
    }
    
}