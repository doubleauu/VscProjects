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
const int B = 271;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;


struct M {
	string name, id;
	int time;
	string res;
};


ll hash(string name) {
	ll ans = 0;
	while(name.size()>0) {
		ans = ans*B + name.back();
	}
	return ans;
}

string _hash(ll n) {
	
}

int res[N];

void solve() {
	int s;
	cin >> s;
	vector<string> v;  // 记录每个队伍编号；
	vector<M> a(s+1);
	vector<M> t; // 记录未知提交；
	for(int i = 1; i <= s; i++) {
		cin >> a[i].name >> a[i].id >> a[i].time >> a[i].res;
		if(a[i].res == "Unknown") t.pb(M);
		else {
			int t = hash(a[i].name);
			if(a[i].res == "Rejected") {
				res[t].
			}
			
		}
	}
	
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