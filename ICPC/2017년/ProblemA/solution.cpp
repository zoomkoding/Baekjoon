#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> p, q;

int main(){
    int n, m, c1, c2, tmp;
    scanf(" %d %d %d %d", &n, &m, &c1, &c2);

    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        p.push_back(tmp);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        q.push_back(tmp);
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    
    int pcnt = 0, qcnt = 0, ans_d = INT_MAX, ans_n = 0;
    while(!(pcnt == n - 1 && qcnt == m - 1)) {
        if(p[pcnt] >= q[qcnt]) {
            if(ans_d > (p[pcnt] - q[qcnt])) {
                ans_d = p[pcnt] - q[qcnt];
                ans_n = 1;
            }
            else if (ans_d == (p[pcnt] - q[qcnt]))
                ans_n++;
            if(qcnt < m-1)
                qcnt++;
            else
                pcnt++;
        }
        else {
            if(ans_d > -p[pcnt] + q[qcnt]) {
                ans_d = -p[pcnt] + q[qcnt];
                ans_n = 1;
            }
            else if (ans_d == (-p[pcnt] + q[qcnt]))
                ans_n++;
            if(pcnt < n-1)
                pcnt++;
            else
                qcnt++;
        }
    }

    printf("%d %d", ans_d + abs(c1 - c2), ans_n);

    return 0;
}