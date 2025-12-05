#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    int cur = 1;
    while (cur < n) {
        cout << cur << ' ';
        cur *= 2;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}