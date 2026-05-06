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
bool isr(int n) {
	return n%400==0 || (n%100!=0 && n%4==0);
}

bool ishf(int y, int m, int d) {
	vector<int> ct(10);
	auto f = [&](int n) -> void{
		for(auto i : to_string(n)) {
			ct[i-'0']++;
		}
	};
	f(y); f(m); f(d);
	int b = 0;
	for(int i = 0; i <= 9; i++) {
		if(ct[i]&&!b) b = ct[i];
		if(ct[i]&&b) {
			if(ct[i] != b) return false;
		}
	}
	return true;
}

int a[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

void solve() {
	int ans = 0;
	// for(int i = 2239; i <= 2239; i++) {
		// for(int j = 9; j <= 9; j++) {
			// for(int k = 9; k <= b[j]; k++) {
				// if(ishf(i,j,k)) ans++;
			// }
		// }
	// }
// 	
	// for(int i = 2239; i <= 2239; i++) {
		// for(int j = 10; j <= 12; j++) {
			// if(isr(i)) {
				// for(int k = 1; k <= b[j]; k++) {
					// if(ishf(i,j,k)) ans++;
				// }
			// }else {
				// for(int k = 1; k <= a[j]; k++) {
					// if(ishf(i,j,k)) ans++;
				// }
			// }
		// }
	// }
// 	
	// for(int i = 2240; i <= 9875; i++) {
		// for(int j = 1; j <= 12; j++) {
			// if(isr(i)) {
				// for(int k = 1; k <= b[j]; k++) {
					// if(ishf(i,j,k)) ans++;
				// }
			// }else {
				// for(int k = 1; k <= a[j]; k++) {
					// if(ishf(i,j,k)) ans++;
				// }
			// }
		// }
	// }
	// 时间模拟器：
	int y = 2239, m = 9, d = 9;
	while(1) {
		if(ishf(y,m,d)) ans++;
		if(y==9876 && m==1 && d==1) break;
		
		d++;
		int max_day = isr(y) ? a[m] : b[m];
		if(d > max_day) {
			d=1;
			m++;
			if(m>12) {
				y++;
				m=1;
			}
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