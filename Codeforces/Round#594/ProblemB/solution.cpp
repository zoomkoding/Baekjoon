#include <cstdio>
#include <algorithm>
using namespace std;
long long n, arr[100001], a, b;
int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; i++)scanf("%lld", &arr[i]);
    sort(arr, arr + n);
    for(int i = 0; i < n / 2; i++)a += arr[i];
    for(int i = n / 2; i < n; i++)b += arr[i];
    printf("%lld", a*a + b*b);
}