/**
 * @brief: 计算并筛选笔试成绩的前（面试名额*150%）
 */
#include <bits/stdc++.h>
using namespace std;

struct M {               //因为每个成员数据量不为1，使用结构体记录
        int number;
        int score;
    };

bool comp(M n1, M n2) {  //定义一个比较函数，用于sort函数第三个参数
    if(n1.score != n2.score) return n1.score > n2.score;
    else return n1.number < n2.number;
}

int main() {
    int n, m;
    cin >> n >> m;      //总人数和面试人数

    M a[5005] = {};     //初始化所有成员为0
    for(int i = 1; i <= n; i++) {
        cin >> a[i].number >> a[i].score;
    }
    sort(a + 1, a + n + 1, comp);   //对前n项进行排序，使用数组名作为指针代替迭代器，注意sort函数第二个参数位尾后指针，但不会越界

    // for(int i = 1; i <= n; i++) {
    //     cout << a[i].number << ' ' << a[i].score << endl;
    // }

    int sc;    
    sc = a[(int)(m * 1.5)].score;   //使用分数线而不是人数，避免分数一样；
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i].score >= sc) count++;
    }

    cout << sc << ' ' << count << endl;
    for(int i = 1; i <= count; i++) {
        cout << a[i].number << ' ' << a[i].score << endl;
    }
    
    
    
    
    

}