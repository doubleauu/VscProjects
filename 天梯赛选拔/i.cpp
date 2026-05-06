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
	int n, m;
	cin >> n >> m;

    // 先存放左端点为 l 的所有禁止区间的有边界的最小值
	vector<int> minR(m+2, m+1);
    for(int i = 1; i <= n; i++) {
        int L, R;
        cin >> L >> R;
        minR[L] = min(minR[L], R);
    }

    // 所有左端点大于 l 的禁止区间的右边界的最小值；
    // 倒叙动态规划
    vector<int> bound(m+2);
    bound[m+1] = m+1;
    for(int l = m; l >= 1; l--) {
        bound[l] = min(minR[l], bound[l+1]);
    }
    ll ans = 0;
    for(int l = 1; l <= m; l++) {
        if(bound[l]>l) ans += min(bound[l],m+1)-1-l+1;
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