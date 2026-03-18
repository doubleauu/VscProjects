#include <bits/stdc++.h>
using namespace std;

#define maxn  100010  //最大长度；
#define ull unsigned long long // 自动取模类型；
#define B 271  // B 表示进制；

ull Preb[maxn];  // 提前存储 B 的i进制结果
ull Hash[maxn];  // 存储前n个字符的哈希值；

void init(int n, const string s) {
    Preb[0] = 1;
    Hash[0] = s[0];
    for(int i = 1; i < n; ++i) {
        Hash[i] = Hash[i-1] * B + s[i];
        Preb[i] = Preb[i-1] * B;
    }
}

ull get(int l, int r) {  // 获取l,r区间子串的hash值；
    if(l == 0) {
        return Hash[r];
    }
    return Hash[r] - Hash[l-1] * Preb[r-l+1];
}

int main() {
    string s = "euqifeuqedqwef";
    init(s.size(), s);
    cout << get(0,2) << "\n";
    cout << get(5,7) << "\n";


    
}