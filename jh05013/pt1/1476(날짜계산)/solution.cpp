#include <cstdio>

int main(){
    int e, s, m;
    scanf("%d %d %d", &e, &s, &m);
    int s_left = s % 28, m_left = m % 19;
    while(1){
        if(e % 28 == s_left && e % 19 == m_left && e >= m && e >= s) {
            printf("%d", e);
            break;
        }
        e += 15;
    }
}