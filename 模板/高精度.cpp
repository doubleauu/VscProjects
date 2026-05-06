
//目前只考虑正整数；
#include <bits/stdc++.h>
using namespace std;

string jiafa(string s1, string s2) {
    string ans;
    int len1 = s1.size(), len2 = s2.size();
    int lenmax = len1 > len2 ? len1 : len2;
    int lenmin = len1 < len2 ? len1 : len2;
    
    //因为要从个位开始算，将字符串反转；
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    //统一长度,避免越界访问；
    if(len1 < len2) {
        for(int i = 1; i <= len2-len1; i++) {
            s1 += "0";
        }
    }else {
        for(int i = 1; i <= len1-len2; i++) {
            s2 += "0";
        }
    }

    // 模拟列算式：
    int t1 = 0, t2 = 0, t3 = 0;  // 分别存两个当前位，一个进位
    for(int i = 0; i < lenmax; i++) {
        t1 = s1[i] - '0';
        t2 = s2[i] - '0';
        int t = t1 + t2 + t3; //记得加上进位； 
        ans += to_string(t%10);
        t3 = t/10;
    }
    if(t3) ans += to_string(t3);
    reverse(ans.begin(),ans.end());
    return ans;
}

string jianfa(string s1, string s2) { //如果出现负数，再递归一次？
    string ans;
    int len1 = s1.size(), len2 = s2.size();
    int lenmax = len1 > len2 ? len1 : len2;
    int lenmin = len1 < len2 ? len1 : len2;
    
    //因为要从个位开始算，将字符串反转；
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    //统一长度,避免越界访问；
    if(len1 < len2) {
        for(int i = 1; i <= len2-len1; i++) {
            s1 += "0";
        }
    }else {
        for(int i = 1; i <= len1-len2; i++) {
            s2 += "0";
        }
    }

    // 模拟列算式：
    int t1 = 0, t2 = 0, t3 = 0;  // 分别存两个当前位，一个借位；
    bool b = false;  //是否借位了；
    for(int i = 0; i < lenmax; i++) {
        b = false;   //借位是否归还；
        t1 = s1[i] - '0';
        t2 = s2[i] - '0';
        int t = t1 - t2 - t3; t3 = 0; //借位及时清零；
        if(t < 0) {
            t += 10;
            t3++;
            b = true;
        }
        ans += to_string(t);
    }
    while(ans != "0" && ans[ans.size()-1] == '0') {  //注意结果为0时要正常输出；
        ans.erase(ans.size()-1);
    }
    reverse(ans.begin(),ans.end());
    if(b) {
        string s = "1";
        for(int i = 1; i <= lenmax; i++) {
            s += "0";
        }
        return "-" + jianfa(s,ans);
    }else return ans;
}

string chengfa(string s1, string s2) {  //先乘再加
    string ans;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int len1 = s1.size(), len2 = s2.size();
    
    string st1; //每次结果的权重，即后面要补几个零; 下面因子的权重；
    for(int i = 0; i < len2; i++) {
        int t = s2[i] - '0';  //当前位
        string st2; // 上面因子的权重；
        for(int j = 0; j < len1; j++) {
            int t1 = t * (s1[j] - '0');
            // cout << to_string(t1)+st1+st2 << endl;
            ans = jiafa(ans, to_string(t1)+st1+st2);
            st2 += "0";
        }
        st1 += "0";
    }
    return ans;
}

string chufa(string s1, string s2) {
    if(s2 == "0") return "除数不能为零！";
    string ans;
    // reverse(s1.begin(), s1.end());  // 除法是从高位开始计算，不需要反转；
    // reverse(s2.begin(), s2.end());
    int len1 = s1.size(), len2 = s2.size();

    string t;  //表示当前被减数；
    bool h = false; //是否已经找到首个非零数；
    for(int i = 0; i < len1; i++) {
        int anst = 0; //当前位上结果
        t += " ";
        t[t.size()-1] = s1[i];
        // cout << t << endl;
        bool b = true;
        while(b) {
            b = false;
            string t1 = jianfa(t, s2);
            if(t1[0] != '-') {  //说明可减
                t = t1;
                anst++;
                b = true;
            }
        }
        // cout << anst << endl;
        if(anst || h) { ans += to_string(anst); h = true; }
    }
    if(ans != "") return ans + " 余 " + t;
    else return ("0 余 " + t);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // cout << chufa(s1,s2);

    //printf()无法输出字符串？只能接受const char[]
    // printf("加法：%s\n减法: %s\n乘法: %s\n除法: %s",
    //     jiafa(s1,s2),jianfa(s1,s2),chengfa(s1,s2),chufa(s1,s2));

    cout << "加法：" << jiafa(s1,s2) << "\n";
    cout << "减法：" << jianfa(s1,s2) << "\n";
    cout << "乘法：" << chengfa(s1,s2) << "\n";
    cout << "除法：" << chufa(s1,s2) << "\n";

    // system("pause");
}