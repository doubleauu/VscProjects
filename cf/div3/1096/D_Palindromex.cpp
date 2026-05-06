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
url: https://codeforces.com/contest/2227/problem/D
对于单个元素构成的回文串我们不考虑，其 mex 最大就是 1
想要mex大一点，我们必须把0包含进去，然后是1，2，3，...
有三种情况：
1. 两个零及其之间元素构成回文
2. 左边零单独成回文
3. 右边零单独成回文
然后各自向两边延申，找出最大的 mex
关键是如何快速求 mex：使用 set 记录未出现过的数字，每次求 mex 取首位即可
一个任意数组，其mex的最大值是其长度；
此题中因为重复出现，mex 最大值只能是 n

*/
void solve() {
	int n;
    cin >> n;
    vector<int> a(2*n+1);
    int l = 0, r = 0; // 标记0；
    for(int i = 1; i <= 2*n; i++) {
        cin >> a[i];
        if(!l && a[i]==0) l=i;
        if(l && a[i]==0) r=i;
    }

    int ans = INT_MIN;

    // 先检验两个零之间的：注意区间左开右闭
    vector<int> b(a.begin()+l,a.begin()+r+1);
    vector<int> t(b); reverse(all(t));

    set<int> st,st1,st2;
    for(int i = 0; i <= n; i++) {
        st.insert(i);
        st1.insert(i);
        st2.insert(i);
    }

    if(t==b) {
        int tn = b.size()%2==0 ? b.size()/2-1 : b.size()/2;
        for(int i = 0; i <= tn; i++) st.erase(b[i]);
        ans = max(ans,*st.begin());
        int tl = l-1, tr = r+1;
        while(tl>=1 && tr <=2*n && a[tl]==a[tr]) st.erase(a[tl]),tl--,tr++;
        ans = max(ans,*st.begin());
    }else {
        // 先看左边的 0；
        b.assign(1,0);
        st1.erase(0);
        int tl = l-1, tr = l+1;
        while(tl>=1 && tr <=2*n && a[tl]==a[tr]) st1.erase(a[tl]),tl--,tr++;
        ans = max(ans,*st1.begin());
        // 在看右边的 0；
        b.assign(1,0);
        st2.erase(0);
        tl = r-1, tr = r+1;
        while(tl>=1 && tr <=2*n && a[tl]==a[tr]) st2.erase(a[tl]),tl--,tr++;
        ans = max(ans,*st2.begin());
    }
    cout << ans << endl;

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