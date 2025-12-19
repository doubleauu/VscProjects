/**
 * @brief: 给几个区间端点，并集长度；
 * @think: 起始构成结构体，按起点位置排序，再根据终点判断是否重叠求有效区间长度；
 *         三种情况：断开，延伸，包含
 */
#include <bits/stdc++.h>
using namespace std;

struct M{
    int a;
    int b;
};

bool judge(M n1, M n2) {    //起点相同，终点小靠前，起点不同，起点小靠前    //起点大，终点小？（放到后面）
    if(n1.a == n2.a) return (n1.b < n2.b);
    else return (n1.a < n2.a);
} 

int main() {
    M a[20010] = {};
    a[0].a = a[0].b = INT_MIN;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
    }
    sort(a+1, a+n+1,judge);

    int sum = 0;
    int r = a[0].b;
    for(int i = 1; i <= n; i++) {
        if(a[i].a >= r) {  //如果没有重叠部分，直接加
            sum += (a[i].b - a[i].a);
        }else if(a[i].b > r) {  //有重叠部分但不包含
            sum += (a[i].b - r);
        }
        r = a[i].b > r ? a[i].b : r;
    }
    // for(int i = 1; i <= n; i++) {
    //     if(a[i].a >= a[i-1].b) {  //如果没有重叠部分，直接加
    //         sum += (a[i].b - a[i].a);
    //     }else if(a[i].b > a[i-1].b) {  //有重叠部分但不包含
    //         sum += (a[i].b -a[i].a -(a[i-1].b - a[i].a));
    //     }
    //     // else {  //如果区间起点小于上一个区间终点，减去重合部分
    //     //     sum += (a[i].b -a[i].a -(a[i-1].b - a[i].a));
    //     // }
    // }
    cout << sum <<endl;
    return 0;
     

}