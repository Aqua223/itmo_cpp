#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define int long long

const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int minOddDivisor(int n) {
    int i = 3;
    while (i * i <= n && n % i) {
        i += 2;
    }
    if (i * i > n) {
        return 1;
    }
    return i;
}

struct node {
    int set, is_divided, to_divide;
};

struct Tree {
    vector<node> tree;
    int size = 1;

    void init(int n) {
        while (size < n) {
            size *= 2;
        }
        tree.assign(2 * size - 1, { 1, 0, 1 });
    }

    void build(vector<int>& a, int tl, int tr, int x) {
        if (tr - tl == 1) {
            if (tl < sz(a)) {
                tree[x].set = a[tl];
                tree[x].to_divide = minOddDivisor(a[tl]);
            }
            return;
        }
        int m = (tl + tr) / 2;

        build(a, 2 * x + 1, tl, m);
        build(a, 2 * x + 2, m, tr);

        tree[x].set = tree[2 * x + 1].set * tree[2 * x + 2].set;
        tree[x].set %= MOD;

        tree[x].to_divide = tree[2 * x + 1].to_divide * tree[2 * x + 2].to_divide;
        tree[x].to_divide %= MOD;
    }

    void build(vector<int>& a) {
        build(a, 0, size, 0);
    }

    void propagate(int x, int tl, int tr) {
        if (tr - tl == 1 || !tree[x].is_divided) {
            return;
        }

        tree[x].set /= tree[x].to_divide;

        tree[2 * x + 1].is_divided = 1;
        tree[2 * x + 2].is_divided = 1;

        tree[x].is_divided = 0;
    }

    void set(int x, int tl, int tr, int i, int v) {
        propagate(x, tl, tr);
        if (tr - tl == 1) {
            tree[x].set = v;
            tree[x].to_divide = minOddDivisor(v);
            return;
        }
        int m = (tl + tr) / 2;

        if (i < m) {
            set(2 * x + 1, tl, m, i, v);
        }
        else {
            set(2 * x + 2, m, tr, i, v);
        }

        tree[x].set = tree[2 * x + 1].set * tree[2 * x + 2].set;
        tree[x].set %= MOD;

        tree[x].to_divide = tree[2 * x + 1].to_divide * tree[2 * x + 2].to_divide;
        tree[x].to_divide %= MOD;
    }

    void set(int i, int v) {
        set(0, 0, size, i, v);
    }

    void update(int x, int tl, int tr, int l, int r) {
        propagate(x, tl, tr);
        if (l >= tr || r <= tl) {
            return;
        }
        else if (l <= tl && r >= tr) {
            tree[x].d *= maxOddDivisor(tree[x].g);
            return;
        }
        int mid = (tl + tr) / 2;

        update(2 * x + 1, tl, mid, l, r);
        update(2 * x + 2, mid, tr, l, r);
    }

    void update(int l, int r) {
        update(0, 0, size, l, r);
    }

    int calc(int x, int tl, int tr, int l, int r) {
        if (l >= tr || r <= tl) {
            return 0;
        }
        else if (l <= tl && r >= tr) {
            return tree[x].set / tree[x].d;
        }
        int mid = (tl + tr) / 2;

        int res1 = calc(2 * x + 1, tl, mid, l, r);
        int res2 = calc(2 * x + 2, mid, tr, l, r);

        return (res1 * res2) % MOD;
    }

    int calc(int l, int r) {
        return calc(0, 0, size, l, r);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int& i : a) cin >> i;

    int m; cin >> m;
    Tree T; T.init(n); T.build(a);
    while (m--) {
        char q; cin >> q;
        if (q == '?') {
            int l, r; cin >> l >> r;
            cout << T.calc(l, r);
        }
        else if (q == '/') {
            int l, r; cin >> l >> r;
            T.update(l, r);
        }
        else {
            int i, v; cin >> i >> v;
            T.set(i, v);
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}
