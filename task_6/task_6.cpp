#include <bits/stdc++.h>

using namespace std;

int fib(int a) {
    int v1 = 0, v2 = 1;
    int n = 2;

    while (v1 + v2 < a) {
        int tmp = v1 + v2;
        v1 = v2; v2 = tmp;
        n += 1;
    }
    return v1 + v2 == a ? n : -1;
}

void solve() {
    unsigned a; cin >> a;

    cout << fib(a) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}