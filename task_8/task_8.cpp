#include <bits/stdc++.h>

using namespace std;

void solve() {
    string dna; cin >> dna;

    for (char& el : dna) {
        if (el == 'A') {
            el = 'T';
        }
        else if (el == 'T') {
            el = 'A';
        }
        else if (el == 'C') {
            el = 'G';
        }
        else if (el == 'G') {
            el = 'C';
        }
    }

    cout << dna << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}