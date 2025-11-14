/**
 * @brief:将1-9分组，满足所给比例
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    string s = "123456789";
    int count = 0;  //记录答案法，用于未找到结结果返回no
    for(int i = 1; i <= 333; i++) {
        int a1 = a*i;
        int b1 = b*i;
        int c1 = c*i;
        string s1 = to_string(a1) + to_string(b1) + to_string(c1);
        sort(s1.begin(),s1.end());
        if(s == s1) {
            printf("%d %d %d\n",a1,b1,c1);
            count++;
        }
    }
    if(count == 0) printf("No!!!");
    return 0;
}