
// 模板题目：https://www.luogu.com.cn/record/272661646
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> bit;
int n,m;
// 获取最低位 1 及其后面的0构成的数
ll lowbit(int x) {return x&-x;}
ll pre(int x) {
    ll res = 0;
    for(;x;x-=lowbit(x)) res += bit[x];
    return res;
}

ll sum(int l, int r) {
    return pre(r)-pre(l-1);
}

void add(ll x, ll val) {
    for(; x<=n; x+=lowbit(x)) bit[x] += val;
}

int main() {
    cin >> n >> m;
    bit.assign(n+1,0);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(i,x);
    }

    while(m--) {
        int op;
        cin >> op;
        if(op==1) {
            int x, k;
            cin >> x >> k;
            add(x,k);
        }else {
            int x, y;
            cin >> x >> y;
            cout << sum(x,y) << endl;
        }
    }

}
