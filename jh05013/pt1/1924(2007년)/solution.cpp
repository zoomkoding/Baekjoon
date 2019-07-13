#include <cstdio>
int main(){
  int x, y, m[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
  char day[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  scanf("%d %d", &x, &y);
  printf("%s", day[(y+m[x-2])%7]);
}