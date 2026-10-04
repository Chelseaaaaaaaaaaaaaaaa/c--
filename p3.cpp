#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9 + 7;

class SegmentTree {
private:
	int size;
	vector<int> tree;
	vector<int> lazy;
	
	void push_down(int p) {
		if (lazy[p] != INF) {
			tree[p << 1] = min(tree[p << 1], lazy[p]);
			lazy[p << 1] = min(lazy[p << 1], lazy[p]);
			tree[p << 1 | 1] = min(tree[p << 1 | 1], lazy[p]);
			lazy[p << 1 | 1] = min(lazy[p << 1 | 1], lazy[p]);
			lazy[p] = INF;
		}
	}
	
	void update_internal(int p, int l, int r, int ql, int qr, int val) {
		if (ql <= l && r <= qr) {
			tree[p] = min(tree[p], val);
			lazy[p] = min(lazy[p], val);
			return;
		}
		push_down(p);
		int mid = (l + r) >> 1;
		if (ql <= mid) update_internal(p << 1, l, mid, ql, qr, val);
		if (qr > mid) update_internal(p << 1 | 1, mid + 1, r, ql, qr, val);
		tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
	}
	
	int query_internal(int p, int l, int r, int target) {
		if (l == r) return tree[p];
		push_down(p);
		int mid = (l + r) >> 1;
		if (target <= mid) return query_internal(p << 1, l, mid, target);
		return query_internal(p << 1 | 1, mid + 1, r, target);
	}
	
public:
	SegmentTree(int n) : size(n) {
		tree.assign(3 * n + 1, INF);
		lazy.assign(3 * n + 1, INF);
	}
	
	void reset() {
		fill(tree.begin(), tree.end(), INF);
		fill(lazy.begin(), lazy.end(), INF);
	}
	
	// 区间 [ql, qr] 更新为 min(old, val)
	void range_minimize(int ql, int qr, int val) {
		if (ql > qr) return;
		update_internal(1, 1, size, ql, qr, val);
	}
	
	// 单点查询
	int get(int idx) {
		return query_internal(1, 1, size, idx);
	}
};

class Rotation {
private:
	int N;
	int total_distinct = 0;
	vector<int> arr;
	vector<int> win_ends;
	vector<int> min_ops;
	
public:
	void run() {
		cin >> N;
		
		// 双倍数组处理环形
		arr.resize(2 * N + 10);
		vector<int> freq(N + 1, 0);
		
		for (int i = 1; i <= N; ++i) {
			cin >> arr[i];
			arr[i + N] = arr[i];
			if (++freq[arr[i]] == 1) total_distinct++;
		}
		
		// 滑动窗口计算每个起点 i 对应的最短覆盖终点 win_ends[i]
		win_ends.assign(2 * N + 2, INF);
		fill(freq.begin(), freq.end(), 0);

		int current_distinct = 0;
		int right_ptr = 0;
		
		for (int left_ptr = 1; left_ptr <= 2 * N; ++left_ptr) {
			while (right_ptr < 2 * N && current_distinct < total_distinct) {
				right_ptr++;
				if (++freq[arr[right_ptr]] == 1) current_distinct++;
			}
			
			if (current_distinct == total_distinct) {
				win_ends[left_ptr] = right_ptr;
			} else {
				win_ends[left_ptr] = INF;
			}
			
			if (--freq[arr[left_ptr]] == 0) current_distinct--;
		}

		min_ops.assign(2 * N + 2, INF);
		SegmentTree st(2 * N);
		
		for (int i = 1; i <= N; ++i) {
			if (win_ends[i] <= 2 * N) {
				st.range_minimize(i, win_ends[i], win_ends[i] - 2 * i);
			}
		}
		for (int i = 1; i <= 2 * N; ++i) {
			int val = st.get(i);
			if (val != INF) min_ops[i] = val + i;
		}

		st.reset();
		for (int i = 1; i <= N; ++i) {
			if (win_ends[i] <= 2 * N) {
				st.range_minimize(i, win_ends[i], 2 * win_ends[i] - i);
			}
		}
		for (int i = 1; i <= 2 * N; ++i) {
			int val = st.get(i);
			if (val != INF) min_ops[i] = min(min_ops[i], val - i);
		}
		
		// 线性扫描 (前向)
		int best_start = 0; 
		for (int i = 1; i <= 2 * N; ++i) {
			while (best_start + 1 <= 2 * N && win_ends[best_start + 1] <= i) {
				best_start++;
			}
			if (best_start > 0) {
				min_ops[i] = min(min_ops[i], i - best_start);
			}
		}
		
		// 线性扫描 (后向)
		int min_rpos_suffix = INF;
		for (int i = 2 * N; i >= 1; --i) {
			if (i <= N) {
				if (min_rpos_suffix != INF) {
					min_ops[i] = min(min_ops[i], min_rpos_suffix - i);
				}
			}
			if (win_ends[i] != INF) {
				min_rpos_suffix = min(min_rpos_suffix, win_ends[i]);
			}
		}
		
		for (int i = 1; i <= N; ++i) {
			int ans = min(min_ops[i], min_ops[i + N]);
			cout << ans << (i == N ? "" : " ");
		}
		cout << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	Rotation solver;
	solver.run();
	
	return 0;
}