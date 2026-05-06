#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int mod = 1e9+7;
const int N = 1e6+5;
/*
url: https://www.luogu.com.cn/problem/CF2200E
此类博弈问题一般都是就先手进行分析，讨论必胜的情况；
我们发现结束条件有种，一是非递减，二是全部质数
我们对给出的序列进行第一次分析，有两种情况：
没有操作机会：可能是给出就是非递减，Bob直接赢；可能不是非递减，但是给出都是质数，Alice直接赢；
接下来讨论可以操作的情况：
Alice 先手，想赢的话就要把分解后的两个数大的放前面；
特别的是，当这个数是某一个 质数的多次幂 ，分解到最后一定产生多个相同的质数，不能对Bob产生威胁
我们可以提前处理这些数字，使用大数组标记（因为数据范围范围只有 1e6，可以开足够大小的数组），质数处理也是如此，多测提前跑欧拉筛（使用**倍增法**）
Bob想赢就要把 Alice 制造的逆序对消除；
如果这个逆序对无法删除（大数为质数或则其因子都比小数要大），则Alice必胜
进一步想到，除了之前想到的幂次数，其他非质数都可以分解出来一个较大的质数和一些较小的质数
所以说只要Alice有操作机会和有效操作数字，将必胜
过程中发现，如果幂次数的最小幂底数比后面非质数的最小因数或者幂次数的幂底数要大，也是会产生影响的
或者是某个质数比后面分解产生的最小因数要大，也是 Alice 必胜
那么我们就再循环一次进行判断：直接将数组替换为其映射（质数不变，质数幂映射为底数，非质数替换为最小因数），然后判断是否非递减即可；
*/
int isnp[N];
vector<int> prime;
void oula(int n) {
    isnp[0] = isnp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!isnp[i]) prime.pb(i);
        for(auto p : prime) {
            if(p*i > n) break;
            isnp[p*i] = 1;
            if(i%p==0) break;
        }
    }
}

// 注意我们要找质数幂，才能分解为多个相同的质数；
vector<int> isPower(N);
// 1e6 范围很小， 可以暴力一点
void isp(int n) {
    for(ll a = 2; a*a <= n; a++) {
        if(isnp[a]) continue;
        ll x = a*a;
        while(x <= n) {
            if(isPower[x]==0) isPower[x] = a; //同时记录最小幂底数，注意只在首次进行标记防止覆盖
            x *= a;
        }
    }
}

// 找到最小因数；
vector<int> minf(N);
void factor(int n) {
    minf[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; i*j <= n; j++) {
            if(minf[i*j]==0) minf[i*j] = i; // 只记录第一次标记；
        }
    }
}
void solve() {
	int n;
    cin >> n;
    vector<int> a(n+1);
    bool has1 = 0; // 是否有逆序对，即操作机会
    bool has2 = 0; // 可操作元素
    bool has3 = 0; // 是否需要操作，可能有逆序对但全是质数，无需操作直接结束；
    isnp[1] = 0; // 特殊标记 1 是质数，因为 1 不能分解；
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < a[i-1]) has1 = 1;
        if(isnp[a[i]] && !isPower[a[i]]) has2 =  1;
        if(isnp[a[i]]) has3 = 1;
    }

    // 考虑第三种情况，我们直接将数组替换为其映射，判断其是否是非递减即可；
    bool b = 0; 
    int mi = 1e6;
    for(int i = n; i >= 1; i--) {
        if(isPower[a[i]]) {
            a[i] = isPower[a[i]];
        }else if(isnp[a[i]]){
            a[i] = minf[a[i]];
        }
        if(a[i] > mi) {
            b = 1;
            break;
        }
        mi = min(mi,a[i]);
    }
    // 有操作机会分三种情况：1.有可操作元素 2.无可操作元素但刚好无需操作 3.无可操作元素需要操作，此时看映射序列；
    if(has1) { 
        if((has2 || !has3 || b)) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }else {  // 没有操作机会，bob直接赢
        cout << "Bob" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    oula(1e6);
    isp(1e6);
    factor(1e6);
    while(T--) {
        solve();
    }
    return 0;
}