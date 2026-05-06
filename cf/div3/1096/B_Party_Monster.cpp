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
url: https://codeforces.com/contest/2227/problem/B
wc那我直接把整个串当子串删了如何呢；
*/
void solve() {
	int n;
    cin >> n;
    stack<char> st;
    int l = 0, r = 0;
    for(int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if(c=='(') l++;
        else r++;
        if(!st.empty() && st.top()=='('&&c==')') st.pop();
        else st.push(c);
    }
    if(st.empty()) {
        cout << "yes" << endl;
        return;
    }
    if(l!=r) {
        cout << "no" << endl;
        return;
    }else {
        cout << "yes" << endl;
    }


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