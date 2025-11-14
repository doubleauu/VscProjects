#include<iostream>
using namespace std;

/**
 * @brief: 模拟二进制的转换容易出错，而且很有局限性，应使用位运算符
 */
int main() {
    int num;
    cin >> num;
    for(int i = 7; i >= 0; i--) {
        cout << ((num>>i) & 1);
    }
    return 0;
}



#if 0
int a[8];

void change(int n) {
    for(int i = 7; n > 0; i--) {
        a[i] = n % 2;
        n /= 2;
    }
}

int main()
{
    int num;
    // 从命令行读入一个int型数值
    // 这一个数取自测试集的输入
    cin>>num;

    // 请在下面添加实现代码
    /**********Program**********/
    if(num >= 0) {
        change(num);
        for(int i = 0; i < 8; i++) {
            cout << a[i];
        }
    }else {
        change(-num);
        for(int i = 0; i < 8; i++) {
            a[i] = (!a[i]);  //取反
            // a[i] != a[i];
        }

        //判断加一
        int j = (a[7]+1) / 2;  //进位
        a[7] = (a[7]+1) % 2;
        int i = 6;
        while(j != 0) {  //进位
            j = (a[i]+1) / 2;
            a[i] = (a[i]+1) % 2;
            i--;
        }

        for(int i = 0; i < 8; i++) {
            cout << a[i];
        }
    }
	
    /**********  End  **********/ 
}

#endif