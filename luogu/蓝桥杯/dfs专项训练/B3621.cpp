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
// 我们不知道 n 的长度，不能写确定数量的for， 则使用递归
// 转换题意为依次从 1-n 位 填充 1-k 的值；
int n, k;
vector<int> t;
vector<int> a;
void dfs(int now) {
	if(now == n+1) {
		for(int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i = 1; i <= k; i++) {
		a[now] = i;
		dfs(now+1);  // 填完这一位填下一位；
	}
}
void solve() {
    cin >> n >> k;
	a.assign(n+1,0);
	dfs(1);
	// for(int i = 0; i < n; i++) {
		// t[i] = i+1;
	// }
    // for(int i = 1; i <= k; i++) {  //从 i 开始
    	// for(int j = 1; j <= n; j++) {  // j 元
//     		
    	// }
    // }
    // if(n==1) {
        // for(int i = 1; i <= m; i++) {
            // cout << i << endl;
        // }
    // }else if(n==2) {
        // for(int i = 1; i <= m; i++) {
            // for(int j = 1; j <= m; j++) {
                // cout << i << " " << j << endl;
            // }
        // }
    // }else if(n==3) {
        // for(int i = 1; i <= m; i++) {
            // for(int j = 1; j <= m; j++) {
                // for(int k = 1; k <= m; k++) {
                    // cout << i << " " << j <<" " << k << endl;
                // }
            // }
        // }
    // }else if(n==4) {
        // for(int i = 1; i <= m; i++) {
        	// for(int j = 1; j <= m; j++) {
        		// for(int k = 1; k <= m; k++) {
        			// for(int p = 1; p <= m; p++) {
        				// cout << i << " " << j << " " << k << " " << p << endl;
        			// }
        		// }
        	// } 
        // }
    // }else {
    	// for(int i = 1; i <= m; i++) {
        	// for(int j = 1; j <= m; j++) {
        		// for(int k = 1; k <= m; k++) {
        			// for(int p = 1; p <= m; p++) {
        				// for(int q = 1; q <= m; q++) {
	        				// cout << i << " " << j << " " << k << " " << p << " " << q << endl;
        				// }
        			// }
        		// }
        	// } 
        // }
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