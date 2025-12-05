#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int cnt = 0;

    while (n--) {
        int v; cin >> v;
        cnt += (v > 0);
    }
    
    cout << cnt << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}