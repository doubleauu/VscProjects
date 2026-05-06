// Problem: 只留专一数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127265/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
using namespace std;
using ll = long long;

const int N = 1e3+10;
int isnp[N];
vector<int> prime;


void oula(int n) {
    prime.clear();
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


int main() {
	oula(N);
	fill(isnp,isnp+N,1);
	for(int p : prime) {
		int t = p;
		while(t <= N) {
			isnp[t] = 0;
			t *= p;
		}
	}
 	int t;
 	cin >> t;
 	while(t--) {
 		int n;
 		cin >> n;
 		vector<int> a(n+1);
 		bool has = 0;
 		for(int i = 1; i <= n; i++) {
 			cin >> a[i];
 			if(!isnp[a[i]]) has = 1;
 		}
 		
		if(has) cout << "YES" << endl;
		else cout << "NO" << endl;
 		
 	}   
}