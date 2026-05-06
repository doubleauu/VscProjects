// Problem: Random
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120563/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：互质具有传递性？没有
*/
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
const int p = 1e9+7;
const int N = 1e9;

int gcd(int a, int b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}
bitset<N> isnp;
vector<int> prime;

void oula(int n) {
	isnp[0] = isnp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!isnp[i]) {
            prime.push_back(i);
        }
        for(int p : prime) {
            if(1LL*i*p > n) break;
            isnp[i*p] = true;  
            
            //考虑下一个合数有更小的质因数，所以if判断放在后面
            if(i % p == 0) break;  //保证每个合数是被最小质因数筛掉
        }
    }
}
void solve() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<int> b;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i]%2==0) {
			cnt++;
			b.pb(a[i]);
		}
	}
	if(cnt>=2) {
		cout << b[0] <<" " << b[1] << endl;
		return;
	}
	// 全是奇数：
	vector<int> c(a);
	sort(all(c));
	auto it = unique(all(c));
	int now = it - c.begin();
	if(now != (a.end()-a.begin())) {
		sort(all(a));
		for(int i = 1;i <= n; i++) {
			if(a[i]==a[i+1]) {
				cout << a[i] << " " << a[i] << endl;
				return;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = n; j > i; j--) {
			if(gcd(a[i],a[j]) > 1) {
				cout << a[i] << " " << a[j] << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	// oula(1e6);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}  
}