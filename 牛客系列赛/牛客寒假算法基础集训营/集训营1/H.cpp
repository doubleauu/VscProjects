// Problem: Blackboard
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/H
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：或满足结合率吗？满足！
	按位或与按位加的结果相同当且仅当这两个数的二进制表示每一位（一个0一个1）或（均为0），即不进位！
	二者都满足结合率，所以运算优先级好像没什么用？
	// 判断一个数字前面的加号是否可以变换，就看整个式子中有没有单个或者多个的和与其满足相或不变；
	
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 998244353;
const int N = 1e6+5;

#include <iostream>
#include <vector>

using namespace std;

// ================= 组合数/排列数模板 START =================

// 【参数设置】
const int MAXN = 200005;        // 根据题目要求修改 N 的上限
const int MOD = 998244353;        // 必须是质数

long long fac[MAXN];    // 阶乘数组 (factorial)
long long invFac[MAXN]; // 阶乘逆元数组 (inverse factorial)

// 【快速幂】计算 a^b % p
long long qpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// 【初始化】预处理阶乘和阶乘逆元，复杂度 O(N)
void init_combinatorics() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    // 费马小定理求最大阶乘的逆元: (N!)^(MOD-2)
    invFac[MAXN - 1] = qpow(fac[MAXN - 1], MOD - 2);

    // 线性递推求所有逆元: 1/(i!) = (1/(i+1)!) * (i+1)
    for (int i = MAXN - 2; i >= 0; i--) {
        invFac[i] = (invFac[i + 1] * (i + 1)) % MOD;
    }
}

// 【组合数计算】 C(n, k) -> O(1)
long long nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    // 公式: n! * inv(k!) * inv((n-k)!)
    return fac[n] * invFac[k] % MOD * invFac[n - k] % MOD;
}


// ================= 组合数/排列数模板 END =================



// bool judge(ll x, ll y) {
	// int maxn = (x > y ? x : y);
	// string s;
	// while(maxn != 0) {
// 		
	// }
// }
// 
int main() {
	init_combinatorics();
	
 	int t;
 	cin >> t;
 	while(t--) {
 		int n;
 		cin >> n;
 		ll cnt = -1;  // 第一位前面是零，多加了一个
 		vector<int> a(n+1);
 		vector<int> pre(n+1);
 		for(int i = 1; i <= n; i++) {
 			cin >> a[i];
 			pre[i] = pre[i-1]+a[i];
 			if((a[i]|a[i-1]) == a[i]+a[i-1]) cnt++;
 		}
 		cerr << (bool)((2|3) == 2+3) << endl;
 		ll ans = 1;
 		for(int i = 1; i <= cnt; i++) {
 			ans = (ans + nCr(cnt,i))%p;
 		}
 		cout << ans << endl;
 		
 		
 	}
}