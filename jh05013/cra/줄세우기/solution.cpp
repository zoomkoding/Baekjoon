#include <string>
#include <cstdio>

using namespace std;

struct subset {
    int parent;
    int rank;
};

struct subset *subsets;

int find(int i){
    if(subsets[i].parent != i)subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent;
}

void Union(int x, int y){
    int xroot = find(x);
    int yroot = find(y);
    if(subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank ++;
    }
}

int print(int i){
    printf("%d ", i);
    if(subsets[i].parent != i)subsets[i].parent = print(subsets[i].parent);
    return subsets[i].parent;
}

int main(){
  int n,m,c,src,dst;
  scanf("%d %d", &n, &m);
  
  subsets = (struct subset*) malloc( (n+1) * sizeof(struct subset) );
  for (int v = 0; v < n+1; ++v) {
      subsets[v].parent = v;
      subsets[v].rank = 0;
  }


  for(int i = 0; i < m; i ++){
    scanf("%d %d", &dst, &src);
    Union(src, dst);
  }
//   for(int i = 1; i <= n; i++)printf("%d", subsets[i].parent);
//   printf("\n");

  for(int i = 1; i <= n; i++){
      printf("%d ", i);
      print(i);  
      printf("\n");    
  }
}