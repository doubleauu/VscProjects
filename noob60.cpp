/**
 * @brief: 考试选项判断；
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;  

    while(T--) {
        string opt[4];
        int len[4]; //先求每个选项长度；
        for (int i = 0; i < 4; i++) {
            cin >> opt[i];
            len[i] = opt[i].length(); // 或者 len[i] = opt[i].size();
        }

        int minIdx = -1, maxIdx = -1; //记录最短和最长选项位置；

        for(int i = 0; i < 4; i++) {
            int shorter = 0, longer = 0; //记录与第i选项长度的比较结果；
            for(int j = 0; j < 4; j++) {  //每个选项进行再进行四次比较
                if (i == j) continue;
                if (len[i] < len[j]) shorter++;
                if (len[i] > len[j]) longer++;
            }
            if(shorter == 3) minIdx = i;
            if(longer == 3) maxIdx = i;
        }

        //满足只有一个严格短且没有严格长，选短；只有一个严格长且没有严格短，选长；否则选C；
        if(minIdx != -1 && maxIdx == -1) {
            cout << char('A' + minIdx) << endl;
        }else if(minIdx == -1 && maxIdx != -1) {
            cout << char('A' + maxIdx) << endl;  //字符的实质为整型，不强转则会输出整型
        }else{
            cout << "C" << endl;
        }
    }
    return 0;
}

