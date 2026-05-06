#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
/*
url: https://codeforces.com/gym/106500/problem/J
先判断不存在解决方案: a-b 和 c-d 必须同号
利用位运算判断同号防止溢出
我们想要总人数最少，发奖数量固定，就需要优胜者尽量多
*/ 
void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a==b) {
        if(c!=d) {
            cout << 0 << endl;
            return;
        }
        if(c%2!=0) {
            ll k = 2*c/(2*a+1);
            cout << c-a*k << endl;
        }else {
            ll k = (2*c-1)/(2*a+1);
            cout << c-a*k << endl;
        }

        
    }else {
        if((c-d)%(a-b) != 0) {
            cout << 0 << endl;
            return;
        }
        ll k = (c-d)/(a-b);
        ll n = c-a*k;
        if(n >= ceil(k*1.0/2)) cout << n << endl;
        else cout << 0 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}