#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll x) {
    if(x <= 1) return 0;
    else {
        for(int i =2; i <= sqrt(x); i++){
            if(x % i ==0) return 0;
        }
    }
    return 1;
}

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if(isPrime(a)) continue;
        // set<ll> s;
        int count = 0;
        for(ll i = 1; i <= sqrt(a); i++) {
            if(a % i == 0) {
                if(i*i == a) {
                    count++;
                }else count += 2;
                // s.push_back(i);
                // s.push_back(a/i);
            }
        }
        if(isPrime(count)) ans += a;
    }
    cout << ans;
}