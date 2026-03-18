// Problem: 方豆子
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/126270/L
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a = "******\n******\n******\n***...\n***...\n***...";
string b = "......\n......\n......\n...***\n...***\n...***";

int arr[11];  //注意每一级别豆子符号数不是一次增加6,而是每次增加一倍;

void dfs(string& a, string& b, int n, int m) {
	if(m == n) return;
	string s1; //上一级好豆子加好豆子
	string s2; //坏豆子加坏豆子
	string s3; //坏豆子加好豆子
	string s4; //找好豆子加坏豆子
	
	int i = 0; int t = 0;
	while(i < (int)a.size()) {
		if(a[i] == '\n') {
			s1.append(a,t,6*arr[m]);
			t = ++i;   //更新新的起始点；
			s1 += "\n";
			continue;
		}
		s1.append(a,i,6*arr[m]);
		i += 6*arr[m];
		if(i == (int)a.size()) {
			s1.append(a,t,6*arr[m]);
		}
	}
	
	i = 0; t = 0;
	while(i < (int)b.size()) {
		if(b[i] == '\n') {
			s2.append(b,t,6*arr[m]);
			t = ++i;   //更新新的起始点；
			s2 += "\n";
			continue;
		}
		s2.append(b,i,6*arr[m]);
		i += 6*arr[m];
		if(i == (int)b.size()) {
			s2.append(b,t,6*arr[m]);
		}
	}
	
	//找坏豆子加好豆子
	i = 0; t = 0;
	while(i < (int)b.size()) {
		if(b[i] == '\n') {
			s3.append(a,t,6*arr[m]);
			t = ++i;   //更新新的起始点；
			s3 += "\n";
			continue;
		}
		s3.append(b,i,6*arr[m]);
		i += 6*arr[m];
		if(i == (int)b.size()) {
			s3.append(a,t,6*arr[m]);
		}
	}
	
	//找好豆子加坏豆子
	i = 0; t = 0;
	while(i < (int)a.size()) {
		if(a[i] == '\n') {
			s4.append(b,t,6*arr[m]);
			t = ++i;   //更新新的起始点；
			s4 += "\n";
			continue;
		}
		s4.append(a,i,6*arr[m]);
		i += 6*arr[m];
		if(i == (int)a.size()) {
			s4.append(b,t,6*arr[m]);
		}
	}
	a = s2+"\n"+s3;
	b = s1+"\n"+s4;
	dfs(a,b,n,++m);
}

int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	for(int i = 2; i < 10; i++) {
		arr[i] = arr[i-1]*2;
	}
	dfs(a,b,n,1);
	cout << a << endl;
}