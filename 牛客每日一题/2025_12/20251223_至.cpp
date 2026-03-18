#include <bits/stdc++.h>
using namespace std;

struct P {
    int x; 
    int y;
};

int main() {
    int n;
    cin >> n;
    vector<vector<int> > a(3, vector<int>(n+1));
    P bing, bong;
    cin >> bing.x >> bing.y;
    cin >> bong.x >> bong.y;
    if(bing.x == bong.x) {
        if(bing.y == bong.y) {
            cout << "YES";
            return 0;
        }else {
            cout << "NO";
            return 0;
        }
    }else if(bing.x == 2) {
        if(bing.y-bong.y == -1) {
            cout << "YES";
        }else if(bing.y-bong.y == 1&& bing.y < n-1){
            cout << "YES";
        }else cout << "NO";
    }else if(bong.y-bing.y == -1) {
        cout << "YES";
    }else if(bing.y-bong.y == -1&& bong.y < n-1){
            cout << "YES";
    }else cout <<"NO";
}