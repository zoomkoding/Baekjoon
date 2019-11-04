#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int q, n, arr[101];

void find(int src, int dst){
    if(src >= dst)return;
    int m = 987654321, m_i = -1;
    for(int i = src; i <= dst; i++){
        if(arr[i] < m)m = arr[i], m_i = i;
    }
    m_i--;
    if(m_i < src)return find(src + 1, dst);
    for(int i = m_i; i >= src; i--){
        swap(arr[i], arr[i + 1]);
    }
    return find(m_i + 1, dst);
}
int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
        find(0, n - 1);
        for(int i = 0; i < n; i++)printf("%d ", arr[i]);
        printf("\n");
    }
    
}