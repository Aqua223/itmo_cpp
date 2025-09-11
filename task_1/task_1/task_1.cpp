#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define int long long

void solve() {
    int n; cin >> n;
    int g = 0, s = 0;

    while (n--) {
        int dg, ds; cin >> dg >> ds;
        g += dg; s += ds;
    }

    g > s ? cout << "Hah id win" : cout << "Stand proud you are strong";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}