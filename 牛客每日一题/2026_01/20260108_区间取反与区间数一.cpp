//直接暴力复杂度太高，使用线段树优化；
//01 串，求几个1就是求区间和, 0和1取反则与1异或即可；
//简单修改b[] 数组的意义将加法线段树改为翻转线段树；

#include <bits/stdc++.h>
using namespace std;

//全局变量便于多处调用
const int maxn = 500005;
int n, q, l, r;
string s;
int a[maxn], b[maxn*4], d[maxn*4]; // b 存储是否翻转，而非加多少， d 存储1的个数（其实还是区间和）

//封装下放函数：
void putdown(int s, int t, int p) {
    int m = s + ((t-s) >> 1);
    if(b[p] && s != t) {
        d[p*2] = (m-s+1) - d[p*2]; b[p*2] ^= 1;  // 此处为异或而不是直接赋1，因为翻转具有抵消性！
        d[p*2+1] = (t-m) - d[p*2+1]; b[p*2+1] ^= 1;
        b[p] ^= 1;
    }
}

void build(int s, int t, int p) {
    if(s == t) {
        d[p] = a[s];
        return;
    }
    int m = s + ((t-s) >> 1);
    build(s, m, p*2);
    build(m+1, t, p*2+1);
    d[p] = d[p*2] + d[p*2+1];
}

void update(int l, int r, int s, int t, int p) {
    if(l <= s && r >= t) {
        d[p] = (t-s+1) - d[p];
        b[p] ^= 1;
        return;
    }

    int m = s + ((t-s) >> 1);
    putdown(s,t,p);

    if(l <= m) update(l, r, s, m, p*2);
    if(r > m) update(l, r, m+1, t, p*2+1);
    d[p] = d[p*2] + d[p*2+1];
}

int getsum(int l, int r, int s, int t, int p) {
    if(l <= s && r >= t) {
        return d[p];
    }

    int m = s + ((t-s) >> 1);
    putdown(s,t,p);

    int sum = 0;
    if(l <= m) {
        sum += getsum(l,r,s,m,p*2);
    }
    if(r > m) {
        sum += getsum(l,r,m+1,t,p*2+1);
    }
    return sum;
}

int main() {
    cin >> n >> q >> s;

    s = "-" + s;
    for(int i = 1; i <= n; i++) {
        a[i] = s[i] - '0';
    }
    build(1,n,1);

    while(q--) {
        int op;
        cin >> op >> l >> r;
        if(op == 1) {
            update(l,r,1,n,1);
        }else {
            cout << getsum(l,r,1,n,1) << endl;
        }
    }
}

