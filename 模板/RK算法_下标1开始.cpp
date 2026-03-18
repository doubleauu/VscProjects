#include <bits/stdc++.h>
using namespace std;

#define maxn  100010
#define B 271
#define ull unsigned long long // 自动取模类型；


ull Hash[maxn];  // 变量名只能命名为Hash，否则与标准库产生命名冲突；
ull preb[maxn];

//下标从1开始；
void init(int n, string s) {
    s = " " + s; // 使其下标从 1 开始；
    preb[0] = 1;
    Hash[0] = 0;
    for(int i = 1; i <= n; i++) {
        preb[i] = preb[i-1] * B;
        Hash[i] = Hash[i-1] * B + s[i];
    }
}


//我们以s[l] 为子串起点， Hash[l-1] 从Hash[l]开始多记了 r-l+1  次，减去即可；
ull get(int l, int r) {   
    return Hash[r] - Hash[l-1] * preb[r-l+1];
}


int main() {
    string s = "34rf3498rewif34rfjwpe34834rfr9efe"; // 原串
    string t = "34rf";  // 需要查询的子串；
    int n = s.size();
    int m = t.size();

    ull target = 0;  // 子串的Hash值；
    for(int i = 0; i < m; i++) {
        target = target * B + t[i];
    }

    // 处理原串的Hash值，可以处理同时判断，也可另写判断语句；
    init(n,s);
    vector<ull> a(n-m+1+1); // 共有n-m加一个子串； 
    for(int i = 1; i <= n-m+1; i++) { //以i为子串起点，i+m-1为终点；
        a[i] = get(i, i+m-1);
    }
    
    int ct = 0;
    for(int i = 1; i <= n-m+1; i++) {
        if(a[i] == target) {
            ct++;
            cout << i << " ";
        }
    }
    cout << "\n" << ct << "\n";


}