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
url: https://codeforces.com/contest/2195/problem/B
首先想到逆序对，使用树状数组统计，但递增排列是固定的，交换的元素也是固定的，好像可以直接遍历；
错了，可以交换的元素并不固定为两个，n*i之间的元素均可自由排列，我们将数组分为多个部分即可；
只查询素数下标即可
不对，应该是按奇数根分组，而不是素数，因为某一个非素数不一定是由素数乘二得来的
但是所有偶数一定可以由前面的奇数乘二得到；
*/
int isnp[N];
vector<int> p;
void oula(int n) {
    isnp[0] = isnp[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(!isnp[i]) p.pb(i);
        for(int j : p) {
            if(1LL*i*j > n) break;
            isnp[i*j] = 1;
            if(i%j==0) break;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1), v(n+1); // 标记是否为排列；
    for(int i =1; i <= n; i++) {
        cin >> a[i];
        if(++v[a[i]] > 1) {
            cout << "no" << endl;
            return;
        }
        // cout << a[i] << " ";
    }
    isnp[1] = 0, isnp[2] = 1;  //特殊标记 1是素数，2 不是素数；
    for(int i = 1; i <= n; i++) {
        if(i%2==0) continue; 
        vector<int> b(1);
        for(int j = i; j <= n; j *= 2) {
            b.pb(a[j]);
        }
        sort(all(b));
        // for(auto i : b) cout << i << " ";
        if(b[1] != i) {
            cout << "no" << endl;
            return;
        }
        for(int j = 2; j < b.size(); j++) {
            if(b[j] != b[j-1]*2) {
                // cout <<j <<" "<< a[j] << " " << a[j-1] <<endl;
                cout << "no" << endl;
                return;
            }
        }
    }
    cout << "yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    oula(2e5);
    while(T--) {
        solve();
    }
    return 0;
}