#include <iostream>
using namespace std;

int n, x, pre[100000];

void post(int start, int end){
    int root = pre[start], l = start + 1, r = -1;
    for(int i = start; i <= end; i++){
        if(root < pre[i]){
            r = i;
            break;
        }
    }
    if(start != end){
        if(r != l){
            if(r != -1) post(l, r - 1);
            else post(l, end);
        }
        if(r != -1)post(r, end);
    }
    cout << root << '\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(!(cin >> x).eof()) pre[n++] = x;
    post(0, n - 1);
}