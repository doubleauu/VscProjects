// 找到所有元素的最大公约数 * n 即可；
// 结果涉及乘法，记得开ll!
#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b,a%b);
}
int main() {
 	int n;
 	cin >> n;
 	int g;
	cin >> g;
	int x;
 	
 	for(int i = 2; i <= n; i++) {
		cin >> x;
 		g = gcd(x,g);
 	}
 	cout << n*g << endl;
}