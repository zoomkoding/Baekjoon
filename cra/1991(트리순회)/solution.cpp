#include <cstdio>
#include <vector>

using namespace std;

int n;
char s, a, b;
vector< vector<int> > v;

void preorder(int n){
    if(n == 0) return;
    printf("%c", 'A' + n - 1);
    preorder(v[n][0]);
    preorder(v[n][1]);

}

void inorder(int n){
    if(n == 0)return;
    inorder(v[n][0]);
    printf("%c", 'A' + n - 1);
    inorder(v[n][1]);
}

void postorder(int n){
    if(n == 0) return;
    postorder(v[n][0]);
    postorder(v[n][1]);
    printf("%c", 'A' + n - 1);

}

int main(){
    v = vector< vector<int> > (27, vector<int>(2,0));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %c %c %c", &s, &a, &b);
        if(a != '.')v[s - 'A' + 1][0] = a - 'A' + 1;
        if(b != '.')v[s - 'A' + 1][1] = b - 'A' + 1;
    }
    preorder(1); printf("\n");
    inorder(1); printf("\n");
    postorder(1); 
}