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
const int mod = 1e9+7;
const int N = 1e6+5;
// int n,m,k,x,y,num,op,sum,cnt,res,ans;

void dfs(vector<vector<int>>& a, int x, int y, int w, int val) {
	if(w==1) {
		a[x][y] = val;
		return;
	}
	dfs(a,x,y,w/2,val);
	dfs(a,x+w/2,y+w/2,w/2, val+w/2*w/2);
	dfs(a,x+w/2,y,w/2,val+w/2*w/2*2);
	dfs(a,x,y+w/2,w/2,val+w/2*w/2*3);
	
}


void solve() {
	int n;
	cin >> n;
	int w = (1<<n);
	vector<vector<int>> a(w+1,vector<int>(w+1));
	dfs(a,1,1,w,1);
	for(int i = 1; i <= w; i++) {
		for(int j = 1; j <= w; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}