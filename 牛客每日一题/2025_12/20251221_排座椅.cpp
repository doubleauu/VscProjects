
//@detail: 使每一条过道分割尽量多的对；
#include <bits/stdc++.h>
using namespace std;

struct P {
    int x = 0; //也可记录坐标
    int y = 0; // 也可记录次数
};

bool comp(P p1, P p2) {
    return p1.y > p2.y;
}

int main() {
    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    vector<P> a(d+1);
    vector<P> b(d+1);
    vector<P> ctn(m); //横着的对，记纵坐标
    vector<P> ctm(n); //竖着的对，记横坐标
    for(int i = 1; i <= d; i++) {
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
        if(a[i].x == b[i].x) ctn[min(a[i].y,b[i].y)].y++;
        else ctm[min(a[i].x,b[i].x)].y++;
    }

    for(int i = 1; i < m; i++) {
        ctn[i].x = i;
        // cout << ctn[i].y << " ";
    }
    for(int i = 1; i < n; i++) {
        ctm[i].x = i;
    }

    sort(ctn.begin()+1, ctn.end(), comp);
    sort(ctm.begin()+1, ctm.end(), comp);

    vector<int> x;
    for(int i = 1; k > 0; i++) {
        x.push_back(ctm[i].x);
        // cout << ctm[i].x << " ";
        // cout << ctm[i].y;
        k--;
    }
    sort(x.begin(), x.end());
    for(int x : x) {
        cout << x << " ";
    }
    cout << endl;
    vector<int> y;
    for(int i = 1; l > 0; i++) {
        y.push_back(ctn[i].x);
        // cout << ctn[i].x << " ";
        // cout << ctn[i].y << " ";
        // cout << endl;
        l--;
    }
    sort(y.begin(),y.end());
    for(int y : y) {
        cout << y << " ";
    }
    


}