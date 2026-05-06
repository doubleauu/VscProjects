//url:https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/#include <bits/stdc++.h>

class Solution {
public:
    #define maxn  100010
    #define B 271
    #define ull unsigned long long // 自动取模类型；


    ull Hash[maxn];  // 变量名只能命名为Hash，否则与标准库产生命名冲突；
    ull preb[maxn];

    void init(int n, string s) {
        preb[0] = 1;
        Hash[0] = s[0];
        for(int i = 1; i < n; i++) {
            preb[i] = preb[i-1] * B;
            Hash[i] = Hash[i-1] * B + s[i];
        }
    }


    ull get(int l, int r) {
        if(l == 0) return Hash[r];
        return Hash[r] - Hash[l-1] * preb[r-l+1];
    }
    int strStr(string s, string t) {
        int n = s.size();
        int m = t.size();

        ull target = 0;  // 子串的Hash值；
        for(int i = 0; i < m; i++) {
            target = target * B + t[i];
        }

        // 处理原串的Hash值，可以处理同时判断，也可另写判断语句；
        init(n,s);
        vector<ull> a(n-m+1+1); // 共有n-m加一个子串； 
        for(int i = 0; i < n-m+1; i++) { //以i为子串起点，i+m-1为终点；
            a[i] = get(i, i+m-1);
        }
        
        int ct = 0;
        for(int i = 0; i < n-m+1; i++) {
            if(a[i] == target) {
                ct++;
                return i;
            }
        }
        return -1;

        }
};