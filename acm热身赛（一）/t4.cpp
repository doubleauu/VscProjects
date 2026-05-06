#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> qx;
vector<ll> qy;

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
    ll x;
    cin >> x;
    ll temp = x;
    if(isPrime(x)) {
        cout << x << endl;
        return 0;
    }
    while(!isPrime(x)) {
        for(int i = 2; i <= sqrt(x); i++) {
            if(x % i == 0) {
                qx.push_back(x/i);
                qy.push_back(i);
                break;
            }
        }
        x = qx[qx.size()-1];
    }

    cout << temp;
    for(int i = 0; i < qx.size()-1; i++) {
        printf(" = (%lld", qx[i]);
    }
    printf(" = (%lld)", qx[qx.size()-1]);

    for(int i = qy.size()-1; i > 0; i--) {
        printf(" * %lld)", qy[i]);
    }
    printf(" * %lld", qy[0]);
    

}