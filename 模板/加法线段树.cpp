//堆式储存的情况下，需要给线段树开 4n 大小的数组
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 10005;
int a[maxn];  // 需要建树的数组
int d[maxn*4]; // 维护的线段树；
int b[maxn*4]; // 懒标记数组；

//对区间[s,t] 建树，当前根的编号位p;
void build(int s, int t, int p) {
    //递归到最深处赋单值；
    if(s == t) {
        d[p] = a[s];
        return;
    }
    //找到根的分节点，位运算的优先级小于加减，减法防止int溢出；
    int m = s + ((t-s) >> 1);
    //递归对左右区间建树；
    build(s, m, 2*p); build(m+1, t, 2*p+1);
    //当递归到最深处对根赋单值，然后再对上层根值进行计算；
    d[p] = d[2*p] + d[2*p+1];
}

//求和区间 [l,r], 当前节点区间 [s,t], 当前节点编号 p;
int getsum(int l, int r, int s, int t, int p) {
    if(l <= s && r >= t) {  // 理论上应该只会相等？
        return d[p];  //当当前节点区间为求和区间子集，返回当前节点值用于累加求和；
    }
    
    int m = s + ((t-s) >> 1);
    int sum = 0;
    if(l <= m) {  // 求和区间与左半部分有交集, 递归查询左儿子
        sum += getsum(l, r, s, m, 2*p);
    }
    if(r > m) {  // 求和区间与右半部分有交集
        sum += getsum(l, r, m+1, t, 2*p+1);
    }

    return sum;
}

//懒标记时对于子节点来说，标记了但并未修改，父节点的值是修改过的；
//懒标记不会全部实现，只实现到能用到的求和区间，然后将懒标记传递下去，减少了复杂度；
void update(int l, int r, int c, int s, int t, int p) {
    if(l <= s && r >= t) {
        d[p] += c * (t-s+1);
        b[p] += c;
        return;
    }
    int m = s + ((t-s) >> 1);
    if(b[p] && s != t) {  //如果节点有懒标记且有子节点，则更新字节点值并将懒标记传给子节点；(处理旧账)
        d[p*2] += b[p] * (m-s+1); b[p*2] += b[p];
        d[p*2+1] += b[p] * (t-m); b[p*2+1] += b[p];
        b[p] = 0;  // 当前节点懒标记清零；
    }
    
    //当修改区间为当前节点区间子集（与左节点或右节点有交集），递归更新子节点；
    if(l <= m) update(l,r,s,c,m,p*2);
    if(r > m) update(l,r,m+1,c,t,p*2+1);
    d[p] = d[p*2] + d[p*2+1];  // 修改是从上往下进行，修改完要及时更新父节点的值；
}

int main() {
    
}
