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
	int n;
	cin >> n;
	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int b = 0; //是否调换顺序
	// a 必须一直主导
	int ct = 0; // 可以调换的次数
	for(int i = 1; i < n; i++) {
		if(a[i]>1 && i%2!=0) {// a 依旧在奇数位置
			cerr << i << endl;
			b = !b;
			ct++;
			i++;
			continue;
		}
		// 只要 a 有机会，可以自定义调换奇数次还是偶数次；
		if(a[i]>1 && i%2==0 && ct>0) {
			cerr << i << endl;
			b = !b;
			ct++;
			i++;
			continue;
		}
		if(a[i]>1) {
			cout << "Bob" << endl;
			return;
		}
	}
	// cout << n << " " << ct << endl;
	if(n%2==0 && ct==0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	
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