#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int& i : a) cin >> i;

    cout << *max_element(a.begin(), a.end()) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}