#include <bits/stdc++.h>

using namespace std;

void solve() {
    // размеры входных чисел не указаны, поэтому буду использовать unsigned int
    int n; cin >> n;
    int mn = INT_MAX, cnt = 0;

    while (n--) {
        unsigned int v; cin >> v;

        if (v == mn) {
            cnt += 1;
        }
        else if (v < mn) {
            cnt = 1;
            mn = v;
        }
    }

    cout << cnt << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}
