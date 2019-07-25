#include <cstdio>
#include <vector>

using namespace std;

 vector<vector<long long> >matrix_multi(vector<vector<long long> > a, vector<vector<long long> > b, long long n){
    vector<vector<long long> > c(n, vector<long long>(n));
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

vector<int> to_binary(long long num){
    vector<int> v;
    while(num != 0){
        v.push_back(num%2);
        num/=2;
    }
    return v;
}

int main(){
    long long n, b, input;
    scanf("%lld %lld", &n, &b);
    vector<vector<long long> > mat1(n, vector<long long>(n));
    vector<vector<long long> > mat2(n, vector<long long>(n));


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &input);
            mat2[i][j] = input;
        }
    }
    for(int i = 0; i < n; i++)mat1[i][i] = 1;
    
    vector<int> v = to_binary(b);
    for(int i = v.size() - 1; i >= 0; i--){
        if(v[i] == 1) {
            mat1 = matrix_multi(mat1, mat1, n);
            mat1 = matrix_multi(mat1, mat2, n);
        }
        else mat1 = matrix_multi(mat1, mat1, n);

    }
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)printf("%lld ", mat1[i][j]);
        printf("\n");
    }
    
}