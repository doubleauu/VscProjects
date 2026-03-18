//简单枚举问题，直接遍历处理就行，注意不同行为（到结尾了或则时间不够了）导致的两种情况（时间不够的退出会导致多做一题）的处理；

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, t;
    cin >> n >> t;
    ll a, b;
    cin >> a >> b;
    vector<ll> T(n+1), N(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> T[i];
    }
    for(ll i = 1; i <= n; i++) {
        cin >> N[i];
    }

    //两个人的独立吗？先算rqy的：
    ll rqy = 0;
    ll rqyt = t;
    // bool br = false;  //是否刷到结尾
 
    for(ll i = 1; i <= n; i++) {
        if(N[i] < b) {  // 简单的一定做
            if(rqyt < T[i]) continue;   // 简单题时间不够也会跳过？！！！！！！！出题人无敌了
            rqyt -= T[i];
            rqy++;
        }else {
            if(rqyt < T[i]*2) continue; // 只有遇到难题且时间不够才会跳过
            else {
                rqyt -= 2 * T[i];
                rqy++;
            }
        }
        if(rqyt < 0) break; // 没时间了就退出
        // if(i == n) br = true;
    }
    if(rqyt < 0) rqy--;  //遍历过程中多做了一道；如果是做到结尾了就不用减；

    //再求cc的；
    ll cc = 0;
    ll cct = t;
    // bool bc = false;
    
    for(ll i = 1; i <= n; i++) {
        if(N[i] >= a) continue;  // 难度大的不做
        else {
            if(cct < T[i]) continue;  // 时间不够的不做
            else {
                cct -= T[i];
                cc++;
            }
        }
        if(cct < 0) break;
        // if(i == n) bc = true;
    }
    if(cct < 0) cc--;

    cout << cc << " " << rqy << "\n";
}