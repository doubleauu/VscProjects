// Problem: 小红的提拉米苏配方 （hard）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127240/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 操作任意次数均可，此时可以用到之前的分类思想
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	
	// 存储1的状态；
	deque<int> a1, a2, a3;
	
	int ct = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			ct++;
			// a.push_back(i);
			if(i < n-1 && s[i+1] == '0') a1.push_back(i);
			// if(i < n-1 && s[i+1] == '1') a2.push_back(i);
			// if(i < n-1 && s[i+1] == '2') a3.push_back(i);
			// if(i == n-1) a1.push_back(i);
            else a2.pb(i);
		}
	}

    vector<int> a(n+1); // 存储改变状态；

    if(a1.size() < a2.size()) {
        for(int i = 0; i < a1.size(); i++) {
            a[i] = 1;
        }
        int tsize = a1.size();
        int t = a2.size()-1;
        while(tsize--) {
            a[a2[t--]] = 2;
        }
    }
    else {
        
    }
    
}