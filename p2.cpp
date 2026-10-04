#include <bits/stdc++.h>
using namespace std;

using Int64 = long long;

struct Participant {
	int rank;
	vector<int> valid_criteria;
	int next_attempt_idx = 0;
};

class Invitation {
private:
	int n, criteria;
	vector<int> quotas;
	vector<int> decline_order;
	vector<Participant> participants;
	vector<set<int>> criterion_pools;
	Int64 rank_sum = 0;
	
public:	
	void init() {
		cin >> n >> criteria;
		
		quotas.assign(criteria + 1, 0);
		for (int i = 1; i <= criteria; ++i) cin >> quotas[i];
		
		decline_order.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> decline_order[i];
		
		participants.resize(n + 1);
		for (int i = 1; i <= n; ++i) {
			int count;
			cin >> count;
			participants[i].rank = i;
			participants[i].valid_criteria.resize(count);
			for (int j = 0; j < count; ++j) {
				cin >> participants[i].valid_criteria[j];
			}
            auto &criteria = participants[i].valid_criteria;
			sort(criteria.begin(), criteria.end());
		}
		
		criterion_pools.resize(criteria + 1);
	}
	
	void place_contestant(int initial_rank) {
		int current_target = initial_rank;
		while (current_target != -1) {
			Participant &p = participants[current_target];
			int displaced_rank = -1;
			
			while (p.next_attempt_idx < (int)p.valid_criteria.size()) {
				int crit_id = p.valid_criteria[p.next_attempt_idx];
				set<int> &pool = criterion_pools[crit_id];
				// case1
				if ((int)pool.size() < quotas[crit_id]) {
					pool.insert(current_target);
					rank_sum += current_target;
					displaced_rank = -1;
					break;
				} 
				// case2
				else {
					int worst_in_pool = *pool.rbegin();
					if (current_target < worst_in_pool) {
						pool.erase(worst_in_pool);
						pool.insert(current_target);
						rank_sum += (current_target - worst_in_pool);
						displaced_rank = worst_in_pool;
						break;
					}
				}
				// try next criterion
				p.next_attempt_idx++;
			}
			current_target = displaced_rank;
		}
	}
	
	void run() {
		vector<Int64> ans(n + 1);
		for (int i = n; i >= 1; --i) {
			place_contestant(decline_order[i]);
			ans[i] = rank_sum;
		}
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << "\n";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	Invitation solver;
	solver.init();
    solver.run();
	
	return 0;
}