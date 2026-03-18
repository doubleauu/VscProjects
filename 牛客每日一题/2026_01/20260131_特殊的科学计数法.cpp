// 模拟进位即可；唯一要注意的点就是最高位可能进位；
// 输出格式限制，使用printf 格式化输出更方便；
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
using namespace std;
using ll = long long;

int main() {
 	string s;
 	cin >> s;
 	int n = s.size();
	char t = s[0];
 	if(s[2]-'0' >= 5) {
 		int t0 = s[0]-'0';
 		int t1 = s[1]-'0';
 		t1++;
 		t0 += t1/10;
 		t1 %= 10;
 		s[1] = char('0'+t1);
 		if(t0 == 10) {
 			t = '1';
 			s[1] = '0';
 			n++;
 		}else {
 			t = char('0'+t0);
 		}
 	}
 	
 	printf("%c.%c*10^%d",t,s[1],n-1);
}