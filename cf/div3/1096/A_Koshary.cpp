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
url: https://codeforces.com/contest/2227/problem/A
至多走一次短步，就是走一次或者走零次
1. 如果走一次：前面长步必须到达 $(x,y-1)$ 或则 $(x-1,y)$ ，一次长步只能移动2，那么这些坐标就必须是 2 的倍数
2. 如果一次不走，就是直接长步到达 $(x,y)$ ，二者是均 2 的倍数
*/
bool hf(int n) {
    return n%2==0;
}
void solve() {
	int x, y;
    cin >> x >> y;
    if((hf(x)&&hf(y)) || (hf(x-1)&&hf(y)) || (hf(x)&&hf(y-1))) {
        cout << "yes" << endl;
    }else cout << "no" << endl;
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