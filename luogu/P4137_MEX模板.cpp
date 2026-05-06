// Problem: P4137 Rmq Problem / mex
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4137
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int N = 2e5+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	set<int> st;  //存放未出现的数字
	for(int i = 0; i <= N; i++) st.insert(i);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		
	}
	vector<int> v(N);
	int tl = 0, tr = 0;
	cin >> tl >> tr;
	for(int i = tl; i <= tr; i++) {
		if(!v[a[i]]) {
			st.erase(a[i]);
			// v[a[i]]++;
		}
		v[a[i]]++;
		
	}
	cout << *st.begin() << endl;
	m--;
	while(m--) {
		int l, r;
		cin >> l >> r;
		while(l > tl) {  //删除操作
			if(v[a[tl]]==1) {
				st.insert(a[tl]);
				// v[a[tl]]--;
			}
			v[a[tl]]--;
			tl++;
		}
		while(l < tl) {  // 添加操作
			tl--;
			if(!v[a[tl]]) {
				st.erase(a[tl]);
				// v[a[tl]]++;
				// cerr << *st.begin() << endl;
			}
			v[a[tl]]++;
			// tl--;
		}
		while(r > tr) {  // 添加操作
			tr++;
			if(!v[a[tr]]) {
				st.erase(a[tr]);
				// v[a[tr]]++;
			}
			v[a[tr]]++;
			// tr++;
			// cerr << *st.begin() << endl;
		}
		while(r < tr) {  // 删除操作
			if(v[a[tr]]==1) {
				st.insert(a[tr]);
				// v[a[tr]]--;
			}
			v[a[tr]]--;
			tr--;
		}
		cout << *st.begin() << endl;
	}
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