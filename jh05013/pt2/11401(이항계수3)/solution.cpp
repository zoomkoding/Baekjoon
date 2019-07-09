#include <vector>
#include <cstdio>

using namespace std;

long long fastPow(long long base, long long exp, long long mod) {
    long long result = 1;
    for (; exp; exp >>= 1, base = (base * base) % mod) {
        if (exp & 1)
            result = (result * base) % mod;
    }
    return result;
}

int main() {
    long long n, k;
    scanf("%d %d", &n, &k);
    long long num1 = 1, num2 = 1;
    for(int i = n - k + 1; i <= n; i++) num1 = (num1 * i) % 1000000007;
    for(int i = 1; i <= k; i++) num2 = (num2 * i) % 1000000007;

    printf("%d",(num1 * fastPow(num2, 1000000005, 1000000007)) % 1000000007);
}