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
url: https://codeforces.com/contest/2195/problem/D
打表找规律，发现相邻做差可以抵消部分系数；
发现 f(1) + f(n) 恰好是 (n-1)倍的 sum;
f(i)-f(i-1) 恰好是以 a[i] 为结尾将整个数组分界，后半部分减去前半部分的值
然后联系两个方程可以得到前半段的值，刚好是前缀和，进一步就可以得到 a 数组；
*/
void solve() {
	int n;
    cin >> n;
    vector<ll> f(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    vector<ll> pre(n+1);
    vector<int> a(n+1);
    ll sum = (f[1]+f[n])/(n-1);
    for(int i = 1; i < n; i++) {
        pre[i] = (sum-(f[i]-f[i+1]))/2;
        a[i] = pre[i]-pre[i-1];
    }
    a[n] = sum-pre[n-1];
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i==n];
    }

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