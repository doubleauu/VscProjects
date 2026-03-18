// Problem: 智乃的幻方
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120565/J
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;
void solve() {
	vector<int> ct(10);
	vector<vector<int> > a(4,vector<int>(4));
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> a[i][j];
			ct[a[i][j]]++;
		}
	}
	for(int i = 1; i <= 9; i++) {
		if(ct[i]!=1) {
			cout << "No" << endl;
			return;
		}
	}
	int sum = 0;
	for(int i = 1; i <= 3; i++) sum+=a[1][i];
	for(int i = 1; i <= 3; i++) {
		int t = 0;
		for(int j = 1; j <= 3; j++) {
			t += a[i][j];
		}
		if(t!=sum) {
			cout << "No" << endl;
			return;
		}
	}
	for(int i = 1; i <= 3; i++) {
		int t = 0;
		for(int j = 1; j <= 3; j++) {
			t += a[j][i];
		}
		if(t!=sum) {
			cout << "No" << endl;
			return;
		}
	}
	int t1 = a[1][1]+a[2][2]+a[3][3];
	if(t1!=sum) {
		cout << "No" << endl;
		return;
	}
	int t2 = a[1][3]+a[2][2]+a[3][1];
	if(t2!=sum) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	
	
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