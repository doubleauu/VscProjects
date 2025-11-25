/**
 * @brief: 求第k小的素数
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8+5;
bool isnp[MAXN];
vector<int> p;

void oula(int n) {
    isnp[0] = isnp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!isnp[i]) {
            p.push_back(i);
        }
        for(int p : p) {
            if(i*p > n) break;
            isnp[i*p] = 1;
            if(i % p == 0) break;
        }
    }
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    oula(n);
    int a;
    for(int i = 0; i < q; i++) {
        scanf("%d", &a);
        printf("%d\n", p[a-1]);
    }
}