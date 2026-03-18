// 题目要判断是否存在方案使棋盘所有数字一样，因为棋盘边缘一圈的数字是不能动的，且为0，所以要把所有数字变为0；
//要去寻找能改变数字到零的方案可能有很多，所以对于此类判断问题，应着手寻找不成立的情况（可结合样例分析）：
/*1. 首先发现当相邻数字相同且不为零时，将不能改变，也就不成立；
 *2. 当该数字大于零时，想要变为0，要一直递减，即一直最大，则四周的数字都应该小于或等于0，否则不成立；
 *3. 当该数字小于零时，四周数字都应该大于或则等于零，否则不成立；
 */
// 除了以上三种情况，其他情况都应成立；（其实是两种，第一种情况包含到了后面两种情况之中）
// 因为数据量不是很大，可以直接暴力遍历；
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<vector<int> > a(n+2, vector<int>(n+2));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int t = a[i][j];
            int t1 = a[i-1][j], t2 = a[i+1][j], t3 = a[i][j-1], t4 = a[i][j+1];
            if(t != 0) {
                // if(t==t1 || t==t2 || t==t3 || t==t4) return false;
                if(t > 0) {
                    if(!(t1 <= 0 && t2 <= 0 && t3 <= 0 && t4 <= 0)) return false;
                }
                if(t < 0) {
                    if(!(t1 >= 0 && t2 >= 0 && t3 >= 0 && t4 >= 0)) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    bool b = solve();
    if(b) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    
}