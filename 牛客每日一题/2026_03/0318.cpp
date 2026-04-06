// url: 
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

// int a[N];
// int diff[N];

// 差分数组，大数组存储舒适区间
// void solve() {
//     int n, p;
//     cin >> n >> p;
//     // for(int i = 1; i <= N; i++) {
//     //     diff[i] = a[i]-a[i-1];
//     // }
//     auto df = [&](int l, int r) -> void {
//         diff[l]++;
//         diff[r+1]--;
//     };
//     while(n--) {
//         int x;
//         cin >> x;
//         df(max(1,x-p),min((int)1e6,x+p));
//     }
//     int ans = INT_MIN;
//     for(int i = 1; i < N; i++) {
//         a[i] = a[i-1]+diff[i];
//         ans = max(ans,a[i]);
//     }
//     cout << ans;

// }

// 滑动窗口在舒适区间中包含尽量多的元素
void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    sort(all(a));
    int l = 0, r = 0;
    int ans = 1;
    while(r < n) {
        if((a[r]-a[l])>2*p) l++;
        else {
            ans = max(ans,r-l+1);
            r++;
        }
    }
    cout << ans;
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