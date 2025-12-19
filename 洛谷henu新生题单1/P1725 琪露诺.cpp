/**
 * @brief: 
 * @details: 感觉还是像求区间的最大值，但是区间起点和终点没有固定规律，下一个区间的起点跟上一次取值点相关，需要（动态规划？）
 *      跟最大值有关，那就维护一个递减的单调队列；
 *      动态规划考虑的是以什么位置为终点而不是起点，所以应该思考可以到达该点的区间与该点状态最值得关系，而不是找下一个区间的起点；
 */
#include <bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
int ans = INT_MIN;
deque<int> dq;
deque<int> site;

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    fill(b, b+N+5, INT_MIN);

    for(int i = 0; i <= N; i++) {
        cin >> a[i];
    }

    // for(int i = L; i <= R; i++) {  //第一个区间内的点不一定从0点来，还有可能是来自于区间前面的部分！！所以不要手动初始化，应全部交给循环内，只需要初始化0点位置
    //     b[i] = a[i];
    // }
    
    b[0] = a[0] = 0;

    // for(int i = L; i <= N; i++) {
    //     for(int j = max(0,i-R); j <= i-L; j++) {  //保证从至少从0点开始内层循环
    //         if(b[j] != INT_MIN) {   //遍历能到达该点的所有状态；同时需要保证该状态可以到达（使用INT_MIN标记不能到达的点）
    //             b[i] = max(b[i],b[j]+a[i]);
    //         }
    //     }
    // }
    for(int i = L; i <= N; i++) {
        // for(int j = max(0,i-R); j <= i-L; j++) {
        int j = max(0,i-L);  //每次只追加一位即可
            while(!dq.empty() && b[j] > dq.back()) {   //使用单调队列优化最值判断，复杂度可达O(n);
                dq.pop_back();
                site.pop_back();
            }
            dq.push_back(b[j]);
            site.push_back(j);
        // }
        if(!dq.empty()) b[i] = dq.front() + a[i];
        if(site.front() <= i-R) {  //出队条件；
            dq.pop_front();
            site.pop_front();
        }
    }
    for(int i = N-R+1; i <= N && i >=0; i++) {  //只在最后的区间内取答案
        ans = max(ans, b[i]);
    }
    cout << ans;

}