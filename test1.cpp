#include <bits/stdc++.h>
using namespace std;


void print1(int a[], int size) {
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
// void print2(int (&a)[n]) {}

int main() {
    int a[5]{1,2,3,4,5};
    // cout << a << endl;
    // cout << *a << endl;
    // cout << 1 << endl;
    int n;
    cin >> n;
    int *a = new int(n);
    cout << n << endl;
    cout << a << endl;
    cout << *a << endl;

    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    return 0;

    
    
}