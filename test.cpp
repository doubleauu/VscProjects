#include <bits/stdc++.h>
using namespace std;

int main() {
	set<int> st;
	st.insert(3);
	auto i = st.insert(3);
	cout << *i.first << endl;
	cout << i.second << endl;
}