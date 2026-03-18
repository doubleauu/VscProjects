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
	string s;
	cin >> s;
	s = "   " +s;
	for(int i = 2; i <= s.size(); i++) {
		// string t; t += s[i];
		// int j = i;
		// while(j > 0 && a[j-1]==' ') j--;
		// if()
		if(s[i] == 'C'&&s[i-1]=='B'&&s[i-2]=='A') {
			s.replace(i-2,3,""); i -= 3;
		}
	}
	for(auto i : s) {
		if(i==' ') continue;
		cout << i;
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