/**
 * @brief: 跳石头，使用二分和judge判断
 */
#include <bits/stdc++.h>
using namespace std;

//需要多处用到的变量定义到全局
int d, n, m;
int nums[50005];   //记录每块砖到终点的距离

bool judge(int x) {
    int count = 0;      //需要移走的数量
    int now = 0;        //当前石头
    int i = 1;          //下一块石头
    while(i <= n+1) {   //直到下一步跳到对岸
        if(nums[i] - nums[now] < x) {   //距离不足就移走下一块石头
            count++;
            i++;        
        }else {      //距离满足就跳过去
            now = i;
            i++;
        }
    }
    if(count <= m) return true;
    else return false;
}

int main() {
    cin >> d >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);  //注意要从1开始，因为起点距离0也是一个有用的元素
    }
    nums[n+1] = d;              //同时注意终点

    int l = 1, r = d;
    int ans = -1;
    while(l <= r) {  //区间左闭右闭
        int mid = l + (r-l)/2;
        if(judge(mid)) {
            ans = mid;
            l = mid + 1;   //找到可行解后继续，目的找最优解
        }else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}