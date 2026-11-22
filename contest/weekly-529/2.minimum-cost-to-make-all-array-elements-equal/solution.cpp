// Created by oportunitas at 2026/11/22 09:32
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-cost-to-make-all-array-elements-equal/
// https://leetcode.com/contest/weekly-contest-529/problems/minimum-cost-to-make-all-array-elements-equal/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /*
        although at first glance this looks like a dp problem, we actually dont need the "timeline"
        paradigm here, we can just look at each "block/run" of consecutive numbers and then
        find the cost of making everything else the same number as that block. then we just
        find the minimum cost between the block options
    */
    long long minCost(vector<int>& nums) {
        using i64 = std::int64_t; 
        const i64 n {ssize(nums)};

        auto runs = nums | views::enumerate | views::chunk_by([](auto a, auto b) {
            return get<1>(a) == get<1>(b);
        });

        // for a run, what's the cost to transform everything to its left and right to the same
        // value as the run itself (i.e. what cost to transform [?,...,?][3,3,3,3,3][?,...,?] to 
        // [3,...,3][3,3,3,3,3][3,...,3])
        auto cost = [n](auto run) -> i64 {
            auto [l, v] = run.front(); auto r = get<0>(run.back());
            
            // ignore begin and end index, just put max value 
            if (r == 0 || l == n - 1) return numeric_limits<i64>::max(); //more modern vs INT64_MAX

            return static_cast<i64>(v) * (n - 1 - (r - l));
        };

        // println("{}", runs | views::transform(cost));
        // return -1;

        return ranges::min(runs | views::transform(cost));
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minCost(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
