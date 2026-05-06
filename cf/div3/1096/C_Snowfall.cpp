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
url: https://codeforces.com/contest/2227/problem/C
如果有 6 或 6的倍数， 则其所在区间乘积一定可以整除，应该放在端点，构成子区间最少
其实放哪里都无所谓好像
同理我们要把乘积得到 6 的倍数的子区间最小长度尽可能大，这样其参与的区间数量就少一些

想到之前写的一道牛客，10 分解为 2*5，6 还可以分解为 2*3，看2，3因子数量，有的尽量放在两端，2，3分开
*/

bool hf2(int n) {return n%2==0;}
bool hf3(int n) {return n%3==0;}
void solve() {
	int n;
    cin >> n;
    vector<int> a(n+1),a2,a3,a6;
    deque<int> ans;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(hf2(a[i]) && hf3(a[i])) a6.pb(a[i]);
        if(!hf2(a[i]) && hf3(a[i])) a3.pb(a[i]);
        if(hf2(a[i]) && !hf3(a[i])) a2.pb(a[i]);
        if(!hf2(a[i]) && !hf3(a[i])) ans.pb(a[i]);
    }
    for(auto i : a6) cout << i << " ";
    for(auto i : a2) cout << i << " ";
    for(auto i : ans) cout << i << " ";
    for(auto i : a3) cout << i << " ";
    cout << endl;

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