// Problem: 初华的扭蛋机
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120564/I
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
	double p1 = 1.0/216;
	double p2 = 15.0/216;
	double p3 = 20.0/216;
	double t0 = 0;
	double t1 = p1*10+p2*3+p1*2;
	double t2 = p1*20+p2*6+p1*4;
	double t3 = p1*30+p2*9+p1*6;
	double t4 = p1*40+p2*12+p1*8;
	double t5 = p1*50+p2*15+p1*10;
	double t6 = p1*60+p2*18+p1*12;
	
	vector<double> ans(7);
	ans[0] = 6;
	ans[1] = 5 + t1;
	ans[2] = 4 + max(t1+t1,t2);
	ans[3] = 3+max(t1+t1+t1,max(t1+t2,t3));
	ans[4] = 2+max(t1+t1+t1+t1,max(t1+t1+t2,max(t1+t3,max(t2+t2,t4))));
	ans[5] = 1+max(t1+t1+t1+t1+t1,max(t1+t1+t1+t2,max(t1+t1+t3,max(t1+t2+t2,max(t2+t3,max(t1+t4,t5))))));
	ans[6] = 0+max(t1+t1+t1+t1+t1+t1,max(t1+t1+t1+t1+t2,max(t1+t1+t1+t3,max(t1+t1+t2+t2,max(t2+t2+t2,max(t1+t1+t4,max(t1+t2+t3,max(t1+t5,max(t2+t4,max(t3+t3,t6))))))))));
	// for(int i = 0; i < 7; i++) {
		// cout << ans[i] << endl;
	// }
	cout <<"######" << endl;
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