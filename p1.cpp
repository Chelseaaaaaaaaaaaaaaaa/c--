#include "bits/stdc++.h"
using namespace std;

struct CowPool {
    vector<int> j2j, j2n, n2j, n2n;
};

void solve(int has_output) {
    int n;
    cin >> n;
    string s_claims, t_claims;
    cin >> s_claims >> t_claims;

    CowPool pool;
    for (int i = 0; i < n; ++i) {
        int l = (s_claims[i] == 'N'), r = (t_claims[i] == 'N');
        if (!l && !r)
            pool.j2j.push_back(i + 1);
        else if (!l && r)
            pool.j2n.push_back(i + 1);
        else if (l && !r)
            pool.n2j.push_back(i + 1);
        else
            pool.n2n.push_back(i + 1);
    }

    if (pool.j2n.size() != pool.n2j.size()) {
        cout << "NO\n";
        return;
    }

    if (pool.j2n.empty()) {
        if (!pool.j2j.empty() && !pool.n2n.empty()) {
            cout << "NO\n";
        } else if (pool.n2n.empty()) {
            cout << "YES\n";
            if (has_output) {
                for (int i = 1; i <= n; ++i) cout << i << (i == n ? "" : " ");
                cout << "\n";
                for (int i = 0; i < n; ++i) cout << 'J';
                cout << "\n";
            }
        } else {
            if (n % 2 != 0)
                cout << "NO\n";
            else {
                cout << "YES\n";
                if (has_output) {
                    for (int i = 1; i <= n; ++i)
                        cout << i << (i == n ? "" : " ");
                    cout << "\n";
                    for (int i = 0; i < n / 2; ++i) cout << "JN";
                    cout << "\n";
                }
            }
        }
        return;
    }

    vector<int> p_order, v_states;
    p_order.reserve(n);
    v_states.reserve(n);

    int s_size = pool.j2n.size();
    for (int i = 0; i < s_size - 1; ++i) {
        p_order.push_back(pool.j2n[i]);
        v_states.push_back(0);
        p_order.push_back(pool.n2j[i]);
        v_states.push_back(1);
    }

    p_order.push_back(pool.j2n.back());
    v_states.push_back(0);
    for (int cow : pool.n2n) {
        p_order.push_back(cow);
        v_states.push_back(1);
    }
    p_order.push_back(pool.n2j.back());
    v_states.push_back(1);
    for (int cow : pool.j2j) {
        p_order.push_back(cow);
        v_states.push_back(0);
    }

    int parity_sum = 0;
    for (int v : v_states) parity_sum += v;

    if (parity_sum % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        if (has_output) {
            for (int i = 0; i < n; ++i) {
                cout << p_order[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
            int current_type = 0;
            for (int i = 0; i < n; ++i) {
                current_type ^= v_states[i];
                cout << (current_type ? 'N' : 'J');
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc, has_output;
    cin >> tc >> has_output;

    while (tc--) {
        solve(has_output);
    }
    return 0;
}