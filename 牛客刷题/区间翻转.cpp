// url: https://www.nowcoder.com/practice/34e434465a3b46d29c581fee5d73bc81?channelPut=tracker3
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
void solve() {
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    // vector<int> a(n+1);
    // for(int i = 1; i <= n; i++) a[i] = i;
    bool b = 1;  // 是否翻转
    int tl = 0, tr = 0;
    while(k--) {
        int l, r;
        cin >> l >> r;
        // 先出后进
        if(l > tl) {
            int t = l-tl;
            while(t--) {
                if(b) {
                    cout << dq.back() << " ";
                    dq.pop_back();
                }else {
                    cout << dq.front() << " ";
                    dq.pop_front();
                }
            }
        }
        b = !b; // 出完后翻转状态；
        if(r > tr) {
            int t = r-tr;
            for(int i = tr+1; i <= r; i++) {
                if(b) dq.pf(i);
                else dq.pb(i);
            }
        }
        tl = l, tr = r;
    }
}

int  main() {
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