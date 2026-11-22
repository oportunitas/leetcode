// Created by oportunitas at 2026/11/22 09:32
// leetgo: 1.4.18
// https://leetcode.com/problems/earliest-signal-activation-times/
// https://leetcode.com/contest/weekly-contest-529/problems/earliest-signal-activation-times/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        using i64 = long long;
        using minheap = priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>>;

        unordered_map<i64, unordered_map<i64, i64>> mat;
        for (const auto& edge : edges) {
            mat[edge[0]][edge[1]] = edge[2];
        } bitset<100005> is_active;

        requiredSignals[0] = 1;
        minheap signalq; signalq.push({0, 0});

        vector<i64> ans (n, -1); ans[0] = 0;
        while (!signalq.empty()) {
            auto [cur_time, cur_node] = signalq.top();
            
            signalq.pop(); requiredSignals[cur_node] -= 1;
            if (is_active[cur_node] || requiredSignals[cur_node] > 0) continue;

            is_active[cur_node] = true;
            ans[cur_node] = cur_time;

            for (const auto& [dest, delay] : mat[cur_node]) {
                if (!is_active[dest]) {
                    signalq.push({cur_time + delay, dest});
                }
            }
        } return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		vector<vector<int>> edges = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		vector<int> requiredSignals = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.earliestActivationTimes(n, edges, requiredSignals);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
