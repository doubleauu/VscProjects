// Problem: 小红的提拉米苏配方（easy）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127240/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 字典序比较问题牢记一点：字典序是从前往后比较，应该是排在后面的优先变2，结果一定不劣（反向思路，我们很难思考最优策略，则与将前面的1变为2的最差情况相反思路即可）
// 所以说我比赛时候分类讨论的思路是错误的！
// easy 版本，我们要操作所有的 成对1 消除掉；结果可能剩下一个或者零个1，可以分情况讨论；如果剩下一个1，此时用到我之前的分类，应该尽量保留尽量靠前的（12）结构中的1（消除会变大），如果没有，就保留尽量靠后的1（（在操作结束后）（其实本身操作结束剩下的 1 就是我们要的））；
// 从两端出发处理前后两个方向上的1， 则使用双指针；
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int n = s.size(); // 返回的是无符号整数，尽量用int存而不要参与运算；
	int ct = 0;

	// 提前存储要保留的 1 的位置，将分类讨论的代码合并；
	bool b = false;   //存在 12 结构；
	int pos = 0;
	for(int i = 0; i < n; i++) {
		if(!b && s[i] == '1' && i < n-1 && s[i+1] == '2') {
			pos = i; 
			b = true;
		}
		if(s[i] == '1') ct++;  // 注意是比较 char 而不是 int ！
	}


	int l = 0, r = n-1;
	bool odd = false;
	if(ct % 2 != 0) {
		odd = true;
	}
	if(odd && b && pos == 0) l = 1;  // 特殊处理首位为 12 结构；
	int t = ct/2; // 一共可以消除 t 次
	while(t--) {
		while(s[l] != '1') {
			l++;
			if(odd && b && l == pos) l++;
		}
		s[l] = '3';
		while(s[r] != '1') {
			if(odd && b && r == pos) r--;
			r--;
		}
		s[r] = '2';
	}
	
	for(int i = 0; i < n; i++) {
		if(s[i] == '3') continue;
		else cout << s[i];
	}
}

// 其实两种情况分看讨论写好像更清晰一点


#if 0
int main() {
	string s;
	cin >> s;
	int n = s.size();
	
	// 存储1的状态；
	deque<int> a1, a2, a3, a4;
	
	int ct = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			ct++;
			// a.push_back(i);
			if(i < n-1 && s[i+1] == '0') a1.push_back(i);
			if(i < n-1 && s[i+1] == '1') a2.push_back(i);
			if(i < n-1 && s[i+1] == '2') a3.push_back(i);
			if(i == n-1) a4.push_back(i);
		}
	}
	
	vector<int> b1, b2;
	
	if(!a4.empty()) {
		b1.push_back(a1.front()); b2.push_back(a4.front());
	    a1.pop_front(); a4.pop_back();
	}
	
	if(a1.size() > a3.size()) {
		while(!(a3.empty())) {
			int t1 = a1.front(), t2 = a3.back();
			a1.pop_front(); a3.pop_back();
			b1.push_back(t1); b2.push_back(t2);
		}
		if(a1.size() > a2.size()) {
			while(!(a2.empty())) {
				int t1 = a1.front(), t2 = a2.back();
				a1.pop_front(); a2.pop_back();
				b1.push_back(t1); b2.push_back(t2);
			}
			if(a1.size() > 1) {
				while(a1.size() > 1) {
					int t1 = a1.front(), t2 = a1.back();
					a1.pop_front(); a1.pop_back();
					b1.push_back(t1); b2.push_back(t2);
				}
			}
		}else {
			while(!(a1.empty())) {
				int t1 = a1.front(), t2 = a2.back();
				a1.pop_front(); a2.pop_back();
				b1.push_back(t1); b2.push_back(t2);
			}
			if(a2.size() > 1) {
				while(a2.size() > 1) {
					int t1 = a2.front(), t2 = a2.back();
					a2.pop_front(); a2.pop_back();
					b1.push_back(t1); b2.push_back(t2);
				}
			}
		}
	}else {
		while(!(a1.empty())) {
			int t1 = a1.front(), t2 = a3.back();
			a1.pop_front(); a3.pop_back();
			b1.push_back(t1); b2.push_back(t2);
		}
		if(a3.size() > a2.size()) {
			while(!(a2.empty())) {
				int t1 = a2.front(), t2 = a3.back();
				a2.pop_front(); a3.pop_back();
				b1.push_back(t1); b2.push_back(t2);
			}
			if(a3.size() > 1) {
				while(a1.size() > 1) {
					int t1 = a3.front(), t2 = a3.back();
					a3.pop_front(); a3.pop_back();
					b1.push_back(t1); b2.push_back(t2);
				}
			}
		}else {
			while(!(a3.empty())) {
				int t1 = a2.front(), t2 = a3.back();
				a2.pop_front(); a3.pop_back();
				b1.push_back(t1); b2.push_back(t2);
			}
			if(a2.size() > 1) {
				while(a2.size() > 1) {
					int t1 = a2.front(), t2 = a2.back();
					a2.pop_front(); a2.pop_back();
					b1.push_back(t1); b2.push_back(t2);
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(binary_search(b1.begin(), b1.end(), i)) continue;
		if(binary_search(b2.begin(), b2.end(), i)) {
			cout << 2;
			continue;
		}
		cout << s[i];
		
	}
	
}

#endif