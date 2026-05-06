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
url: https://codeforces.com/gym/106494/problem/B
向量和为零，转化为首尾相连构成闭合多边形
因为方向任意，我们只需要考虑长度即可
画图发现可以先画短边，最后画长边进行闭合，任意曲折短边短边之间联系
发现满足条件的长边范围必须小于这些短边之和，且大于这些短边相互抵消后剩余的长度（我们选的最长边一定满足此点）
所以我们的问题就是找哪一条边作为最长边，容易想到肯定是l最大或则r最大
如果我们选 r 最大，那么此时最大的那个 l 就可能变为最大边，因为此时 r 最大的点 l 可能很小
所以我们选最大的 l 边作为最长边，然后其他边的和要尽可能地大（目的是大于l），直接选 r 可能会导致产生新的最长边
所以我们先选其他边的 l，在逐渐增加进行构造
*/
void solve() {
	int n;
    cin >> n;
    vector<ll> L(n+1), R(n+1);
    ll lsum = 0, rsum = 0;
    int ma = INT_MIN;
    int pos = -1;
    for(int i = 1; i <= n; i++) {
        cin >> L[i];
        lsum += L[i];
        if(L[i] > ma) {
            ma = L[i];
            pos = i;
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> R[i];
        rsum += R[i];
    }
    if(rsum-R[pos] < ma) {
        cout << -1 << endl;
        return;
    }
    vector<ll> ans = L;
    if(lsum - ma >= ma) {
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    ll need = ma - (lsum-ma);
    for(int i = 1; i <= n&&need > 0; i++) {
        if(i==pos) continue;
        ll add = min(need,R[i]-ans[i]);
        ans[i] += add;
        need -= add;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    // // ma 是当前最长边，res 为其他边之和；
    // ll res = lsum-ma;
    // for(int i = 1; i <= n; i++) {
    //     if(i==pos) continue;
    //     int need = ma-res;
    //     if(R[i]-ans[i]>=need) {
    //         ans[i] += need;
    //         for(int i = 1; i <= n; i++) {
    //             cout << ans[i] << " ";
    //         }
    //         return;
    //     }else {
    //         res += R[i]-ans[i];
    //         // ma = max(ma,R[i]);
    //         // if(res>=ma) {
    //         //     for(int i = 1; i <= n; i++) {
    //         //         cout << ans[i] << " ";
    //         //     }
    //         //     return;
    //         // }
    //     }
    // }

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