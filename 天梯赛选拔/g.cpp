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
	int n, k;
	cin >> n >> k;
	vector<int> a(10);
	while(k--) {
		int x;
		cin >> x;
		a[x]++;
	}
	vector<int> b;
	for(int i = 0; i <= 9; i++) {
		if(a[i]==0) b.pb(i);
	}
	string s = to_string(n);
	string ans;
	for(int i = 0; i < s.size(); i++) {
		int t = s[i]-'0';
		if(a[t]==0) {
			ans += s[i];
		}else {
			for(int j = 0; j < b.size(); j++) {
				if(b[j] > t) {
					ans += '0'+b[j];
					break;
				}
				if(j == b.size()-1) {
					while(ans.size()>0) {
						int tt = ans.back()-'0';
						ans.pop_back();
						for(int k = 0; k < b.size(); k++) {
							if(b[k] > tt) {
								ans += '0'+b[k];
								string tans(s.size()-ans.size(),'0'+b[0]);
								ans += tans;
								cout << ans; return;
							}
						}
					}
					for(int k = 0; k < b.size(); k++) {
						if(b[k]>0) {
							ans = '0'+b[k];
							break;
						}
					}
					string tt(s.size(),'0'+b[0]);
					ans += tt;
					cout << ans;
					return;
				}
			}
			string tt(s.size()-ans.size(),'0'+b[0]);
			ans += tt;
			cout << ans;
			return;
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