// Problem: 小红的奇数奶油球
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127240/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 不知道哪一个是根，就假定 1 是根
// 树状结构可以从上往下看（树根到树叶），dfs 求得是孩子数量（包括自身）；
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

// dfs遍历树节点大小模板；
// int dfs(vector<vector<int> > &a, vector<int>& ct, int fu, int now) {
// 	int sz = 1;  // 父节点本身大小为 1；
// 	for(int i : a[now]) {
// 		if(i == fu) continue;
// 		sz += dfs(a,ct,now,i);
// 	}
// 	ct[now] = sz;
// 	return sz;
// }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int> > a(n+1);   // 定义内部为空数组的方式；
		for(int i = 1; i < n; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			a[t1].push_back(t2);
			a[t2].push_back(t1);
		}
		// dfs 遍历每个子节点的大小；
		vector<int> ct(n+1);

		// c++11支持递归写法的lambda表达式，可省略传参；
		function<int(int,int)> dfs = [&](int fu, int now) {
			int sz = 1;
			for(int i : a[now]) {
				if(i == fu) continue;
				sz += dfs(now,i);
			}
			ct[now] = sz;
			return sz;
		};

		dfs(1,1);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			// bool is = true;
			// vector<int> t;
			// for(int j : a[i]) {
			// 	t.push_back(ct[j]);
			// }
			// int tn = t.size();
			// if(a[i].size() == 1) { // 只有父亲的特殊情况：树叶
			// 	if(n%2 == 0) ans++;
			// 	continue;
			// }
			// if(i == 1) {  // 没有父亲的特殊情况；
			// 	for(int j = 0; j < tn; j++) {
			// 		if(t[j] % 2 == 0) {
			// 			is = false;
			// 			break;
			// 		}
			// 	}
			// 	if(is) ans++;
			// 	continue;
			// }
			
			// sort(t.begin(), t.end()); //一个节点可以有多个孩子，但只能有一个父亲，最大的那个就是父亲！
			// for(int j = 0; j < tn-1; j++) {
			// 	if(t[j] % 2 == 0) {
			// 		is = false;
			// 		break;
			// 	}
			// }
			// if(is) {
			// 	if((ct[1] - ct[i]) % 2 != 0) ans++;  // 父节点所在分支大小等于根节点大小减去该节点大小；
			// }

			// 通用的逻辑，通过比较节点大小判断父子关系；
			int add = 1;
			for(int j : a[i]) {
				if(ct[j] < ct[i] && ct[j]%2 == 0) add = 0; // 孩子
				if(ct[j] > ct[i] && (n-ct[i])%2 == 0) add = 0; // 父亲
			}
			ans += add;
		}
		cout << ans << endl;
	}
}