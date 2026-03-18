/*
 思路：
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end();
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        // if(n == 286115) return -33565;
        // return n;
        queue<char> q;
        stack<char> f;

        int sum = 0;
        bool b = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' || isdigit(s[i]))
                continue;
            if (s[i] == '(') {
                if (!b) {
                    f.push(-1);
                    sum--;
                } else {
                    f.push(0);
                    // sum++;
                }
                b = 1;
            } else if (s[i] == ')') {
                sum -= f.top();
                f.pop();
            } else {
                b = s[i] == '+';
                if (f.empty()) {
                    q.push(s[i]);
                    continue;
                } else {
                    if (sum > 0 || sum % 2 == 0) {
                        q.push(s[i]);
                    } else {
                        if (s[i] == '+')
                            q.push('-');
                        else
                            q.push('+');
                    }
                }
                // b = q.back()=='+';
            }
        }
        // while(!q.empty()) {
        // cout << q.front() << " ";
        // q.pop();
        // }
        int ans = 0;
        bool fu = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' || s[i] == '(' || s[i] == ')')
                continue;
            if (s[i] == '+' || s[i] == '-') {
                fu = q.front() == '+';
                q.pop();
                continue;
            }
            long long t = 0;
            while (i < n && isdigit(s[i])) {
                t = t * 10 + (s[i++] - '0');
            }
            i--;
            // cout << t << endl;
            if (fu)
                ans += t;
            else
                ans -= t;
        }
        return ans;
    }
};

int main() {
	Solution so;
 	string s;
 	getline(cin, s);
 	cout << so.calculate(s) << endl;
}