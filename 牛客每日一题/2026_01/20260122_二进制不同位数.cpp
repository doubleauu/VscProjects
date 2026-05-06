//因为数字不超过九次方，转为二进制也没有多少位，因此直接暴力转换后按位比较就行；
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int am[maxn], an[maxn];

int main() {
    int m, n;
    cin >> m >> n;

    
    int len = 0;
    while(m != 0 || n != 0) {
        am[len] = m&1;
        an[len] = n&1;
        if(m!=0) m >>= 1;
        if(n!=0) n >>= 1;
        len++;
    }

    long long ct = 0;
    for(int i = 0; i <= len; i++) {
        if(am[i]!=an[i]) ct++;
    }
    cout << ct;
}