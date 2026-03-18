// Problem: Tic Tac DREAMIN’
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120563/H
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 思路：
*/
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define pq priority_queue
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int p = 1e9+7;
const int N = 1e6+5;

int main() {
 	double x1,y1,x2,y2;
 	cin >> x1 >> y1 >> x2 >> y2;
 	if(x1==x2&&y1==y2) {
 		cout << "no answer" << endl;
 		return 0;
 	}  
 	if(x1==x2&&y1!=y2) {
 		double d = abs(y1-y2);
 		double h = 4/d;
 		cout << fixed << x1+h << endl;
 		return 0;
 	}
 	
 	if(x1!=x2&&y1==y2) {
 		double d = abs(x1-x2);
 		double h = y1;
 		if(abs(4-d*h) <= 1e-7) {
 			cout << 0 << endl;
 		}else cout << "no answer" << endl;
 		return 0;
 	}
 	// 贯穿 x 轴：高固定；
 	if(y1*y2 < 0) {
 		double x0 = x1-y1*((x2-x1)/(y2-y1));
	 	double h = abs(y1-y2);
	 	double d = 4/h;
	 	cout << fixed << x0+d << endl; 
	 	return 0;
 	}
 	//保证从 x2 切割
 	if(abs(y1) < abs(y2)) {
 		swap(x1,x2);
 		swap(y1,y2);
 	}
 	double x0 = x2+4/abs(y1);
 	double y0 = y2;
 	double x = x1 - y1*((x0-x1)/(y0-y1));
 	cout << fixed << x << endl;
 	
 	
}