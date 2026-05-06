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
url: https://codeforces.com/contest/2200/problem/B
题目说明只要由逆序就可以删除操作，而且是删除任意数字；
所以只要数组中由一个逆序存在，我们就可以保留该逆序对，然后将其他元素全部删除，最后删除二者之一，剩余一个元素
如果一个逆序都没有，则没有操作机会，直接输出 n 即可；
*/
void solve() {
	int n;
    cin >> n;
    vector<int> a(n+1);
    bool b = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < a[i-1]) b = 1;
    }
    if(b) cout << 1 << endl;
    else cout << n << endl;

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