#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans;
    if(m > n) {
        if(m % n == 0) {
            ans = m/n;
        }else ans = m/n + 1;
    }else ans = 1;
    cout << "Average = " << ans << endl;    
}