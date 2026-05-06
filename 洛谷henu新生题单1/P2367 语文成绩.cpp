/**
 * @brief: 对指定区间进行修改
 */
#include <bits/stdc++.h>
using namespace std;

//使用差分 & 前缀和，在多次区间修改时的时间复杂度由O(n)降为O(1)
int main() {
    int n,p;
    scanf("%d%d",&n,&p);
    vector<int> sc(n+1);
    vector<int> diff(n+2);  //当需要更改第n位时，差分数组的n+1位会被访问，分配n+2防止越界
    for(int i = 1; i <= n; i++) {
        scanf("%d",&sc[i]);
        diff[i] = sc[i] - sc[i-1];
    }

    for(int i = 0; i < p; i++) {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        diff[a] += c;
        diff[b+1] -= c;    
    }

    vector<int> preSum(n+1);
    for(int i = 1; i <= n; i++) {
        preSum[i] = preSum[i-1] + diff[i];
    }
    sort(preSum.begin()+1, preSum.end());
    printf("%d", preSum[1]);
    return 0;
}
#if 0
//一般解法
void changeSc(int a, int b, int c, vector<int>& score) {
    for(int i = a; i <= b; i++) {
        score[i] += c;
    }
}

int main() {
    int n,p;
    scanf("%d%d", &n, &p);
    vector<int> score(n+1);  //给定长度时，vector会初始化0
    for(int i = 1; i <= n; i++) {
        scanf("%d", &score[i]);
    }
    for(int i = 0; i < p; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        changeSc(a,b,c,score);
    }
    sort(score.begin()+1,score.end());
    printf("%d", score[1]);
    return 0;
}
#endif