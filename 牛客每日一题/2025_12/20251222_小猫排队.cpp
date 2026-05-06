#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int k;
    int p = n+1;
    cin >> k;
    deque<int> dq;
    deque<int> site;
    for(int i = 1; i <= n; i++) {
        if(a[i] > k) {
            dq.push_back(a[i]);
            site.push_back(i);
        }
    }
    int top = 1;
    int ans = 0;
    while(true) {
        ans++;
        if(!site.empty()) {
            p = site.back();
            site.pop_back();
            dq.pop_back();
        }
        if(p == top) {
            cout << ans;
            return 0;
        }
        if(!site.empty() && site.front() == top) {
            dq.pop_front();
            site.pop_front();
        }
        top++;
    }
}