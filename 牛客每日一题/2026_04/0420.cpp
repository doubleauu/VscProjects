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
url: https://www.nowcoder.com/practice/5b3184b233f34fb39a7f259ae82eb42c?channelPut=tracker2
先看数据范围，一组，字符串长度只有1e5，直接o(n)遍历即可；
分类讨论当前字符是什么即可，找出每一段合法连续的字符串，使用 res 记录最大值；
字符串前面可以加一个空格实现下标从 1 开始，而且不用特判下标为 0 的情况；
*/
void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ans = 0;
    int res = 0;
    a = ' ' +a;
    for(int i = 1; i <= n; i++) {
        if(a[i]=='a'||a[i]=='h') {
            if(a[i] == a[i-1]) {
                ans = 1;
            }else {
                ans++;
                res = max(ans,res);
            }
        }else {
            ans=0;
        }
        // cout << ans << endl;
    }
    cout << res;
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