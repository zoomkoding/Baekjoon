#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n, m;
vector<int> budgets;

int main() {
    scanf("%d", &n);
    budgets = vector<int>(n);
    for(int i = 0; i < n; i++)scanf("%d", &budgets[i]);
    scanf("%d", &m);
    long long sum = 0;
    for(int i = 0; i < budgets.size(); i++)sum += budgets[i];
    sort(budgets.begin(), budgets.end(), greater<int>());
    if(sum < m){
        printf("%d", budgets[0]);
        return 0;
    }
    for(int i = 1; i < budgets.size(); i++){
        int diff = i * (budgets[i-1] - budgets[i]);
        sum -= diff;
        if(sum > m) continue;
        int temp = (m - sum)/i;
        printf("%d", budgets[i] + temp);
        return 0;
    }
    printf("%lu", m/budgets.size());
    return 0;
}