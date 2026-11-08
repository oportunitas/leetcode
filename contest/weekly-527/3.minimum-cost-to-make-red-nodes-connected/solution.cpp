// Created by oportunitas at 2026/11/08 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-cost-to-make-red-nodes-connected/
// https://leetcode.com/contest/weekly-contest-527/problems/minimum-cost-to-make-red-nodes-connected/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (const auto& e : edges) {
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }

        vector<int> order; order.reserve(n); order.push_back(0);
        vector<int> parent (n, -1); parent[0] = 0; //temporary to provide for loop logic
        for (size_t i {0}; i < order.size(); ++i) {
            int curr = order[i];
            for (int next : neighbors[curr]) {
                // if not set yet, this must be below current
                if (parent[next] == -1) {
                    parent[next] = curr;
                    order.push_back(next);
                }
            }
        } parent[0] = -1;

        using i64 = std::int64_t;
        vector<i64> subtree_size (n, 1);
        vector<i64> cost_to_blue (n, 0);
        vector<i64> cost_to_red (n, 0);

        // bottom up to set subtree sizes
        for (int curr : order | views::reverse) {
            if (parent[curr] != -1) subtree_size[parent[curr]] += subtree_size[curr];
        }

        // set per node only cost (assuming only this node remains to connection)
        for (int curr = 0; curr < n; ++curr) {
            cost_to_blue[curr] = colors[curr] == 'R' ? subtree_size[curr] : 0;
            cost_to_red[curr] = colors[curr] == 'B' ? subtree_size[curr] : 0;
        }

        // now we connect up the cost_to_blue and cost_to_red bottom up
        for (int curr : order | views::reverse) {
            if (parent[curr] == -1) continue;
            cost_to_blue[parent[curr]] += cost_to_blue[curr];
            cost_to_red[parent[curr]] += min(cost_to_red[curr], cost_to_blue[curr]);
        }

        i64 total = cost_to_blue[0];
        i64 ans = total;
        for (int curr = 0; curr < n; ++curr) {
            // check if opting to change to red instead is better
            ans = min(ans, total - (cost_to_blue[curr] - cost_to_red[curr]));
        } return ans;


        //  vector<int> order; order.reserve(n); order.push_back(0);
        // vector<int> parent (n, -1); parent[0] = 0; //temporary to provide for loop logic
        // for (size_t i {0}; i < order.size(); ++i) {
        //     int curr = order[i];
        //     for (int next : neighbors[curr]) {
        //         // if not set yet, this must be below current
        //         if (parent[next] == -1) {
        //             parent[next] = curr;
        //             order.push_back(next);
        //         }
        //     }
        // } parent[0] = -1;

        // using i64 = std::int64_t;
        // vector<i64> subtree_size (n, 1);
        // vector<i64> cost_to_blue (n, 0);
        // vector<i64> cost_to_red (n, 0);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		string colors = LeetCodeIO::deserialize<string>(cin);
		vector<vector<int>> edges = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.minCost(n, colors, edges);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
