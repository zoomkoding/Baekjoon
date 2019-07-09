#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

int compare(const void* a, const void* b){
    return strcmp( (char*)a , (char*)b );
}

int main()
{   
    int M,N,i;
    scanf("%d%d", &N,&M);
    char names[N+M][20];
    int count = 0;

    for(i = 0 ; i < N+M ; i++){
        scanf("%s",names[i]);
    } 
    qsort(names, N+M, sizeof(names[0]), compare);
    for(i = 1 ; i < M + N ; i++){
        if(strcmp(names[i-1],names[i]) == 0) count++;
    }
    for(i = 1 ; i < M + N ; i++){
        if(i == 1) printf("%d\n",count);
        if(strcmp(names[i-1],names[i]) == 0) printf("%s\n",names[i]);
    }
}