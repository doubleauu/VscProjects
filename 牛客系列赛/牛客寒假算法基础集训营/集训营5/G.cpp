// Problem: 智乃的箭头魔术
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120565/G
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
int p;
void solve() {
	int n;
	string s;
	cin >> s;
	// int p = 0;
	// while(cin>>n) {
	for(char c: s) {
		int n = c-'0';
		// cout << p << " " << n <<endl;
		// cout << n;
		if(n==0) {
			if(p==0) p=3;
			else if(p==1) p=2;
			else if(p==2) p=1;
			else if(p==3) p=0;
		}else if(n==1) {
			if(p==0) p=0;
			else if(p==1) p=3;
			else if(p==2) p=2;
			else if(p==3) p=1;
		}else if(n==2) {
			if(p==0) p=1;
			else if(p==1) p=0;
			else if(p==2) p=3;
			else if(p==3) p=2;
		}else if(n==3) {
			if(p==0) p=2;
			else if(p==1) p=1;
			else if(p==2) p=0;
			else if(p==3) p=3;
		}else if(n==4) {
			if(p==0) p=1;
			else if(p==1) p=2;
			else if(p==2) p=3;
			else if(p==3) p=0;
		}else if(n==5) {
			if(p==0) p=3;
			else if(p==1) p=0;
			else if(p==2) p=1;
			else if(p==3) p=2;
		}
		cout << p;
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