// Problem: 小苯的输入法
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/130843/B
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
	string s;
	int n;
	cin >> n;
	int b = 1; // 1表示右侧
	while(n--) {
		char c;
		cin >> c;
		if(c=='!') {b = !b;continue;}
		if(c=='-') {
			if(s.size()==0) continue;
			if(b) s.pop_back();
			else s.erase(0,1);
			continue;
		}
		if(b) s.push_back(c);
		else s = c+s;
	}
	if(s.size()==0) cout << "Empty" << endl;
	else cout << s << endl;
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