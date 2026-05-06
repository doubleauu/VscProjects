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
url: https://www.nowcoder.com/practice/9f766daa7e4042a786633c341fe9d7e2?channelPut=tracker2
根据数据范围，我们大概需要在 O(1) 时间得到区间的解；
考虑前缀和；
但是这个是简单版本，q已经限制住了，我们直接在读取的时候 O(n) 计算结果即可；
*/ 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    cin >> a[1];
    ll ans = a[1];
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        ans = ans + a[i] - (ans^a[i]);
    }
    cout<< ans << endl;
    int l, r;
    cin >> l >> r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}