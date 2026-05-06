// Problem: 智乃的瓷砖
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120565/B
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
	char c[] = {'/', '\\'};
	int n, m;
	cin >> n >> m;
	vector<char> a(m+1), b(m+1);
	a[1] = c[0], b[1] = c[1];
	for(int i = 2; i <= m; i++) {
		if(i%2==0) {
			a[i] = c[1]; b[i] = c[0];
		}else {
			a[i] = c[0]; b[i] = c[1];
		}
	}
	for(int i = 1; i <= n; i++) {
		if(i%2!=0){
			for(int j = 1; j <= m; j++) {
				cout << a[j];
			}
			cout << endl;
		}else {
			for(int j = 1; j <= m; j++) {
				cout << b[j];
			}
			cout << endl;
		}
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