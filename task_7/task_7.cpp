#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;

    (b / 7 * 7 >= a) ? cout << b / 7 * 7 << '\n' : cout << -1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}