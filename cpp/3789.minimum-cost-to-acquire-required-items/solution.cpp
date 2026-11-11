// Created by oportunitas at 2026/11/11 14:52
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-cost-to-acquire-required-items/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 9.1MB/99th%)
        we first convert the costs to its lowest possible state, then we just add
    */
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        using i64 = std::int64_t;

        i64 cb = min(costBoth, (cost1 + cost2));
        i64 c1 = min((i64)cost1, cb); i64 c2 = min((i64)cost2, cb);

        i64 n1 = (i64)need1; i64 n2 = (i64)need2;
        i64 pair = min(n1, n2);

        return (pair * cb) + ((n1 - pair) * c1) + ((n2 - pair) * c2);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int cost1 = LeetCodeIO::deserialize<int>(cin);
		int cost2 = LeetCodeIO::deserialize<int>(cin);
		int costBoth = LeetCodeIO::deserialize<int>(cin);
		int need1 = LeetCodeIO::deserialize<int>(cin);
		int need2 = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minimumCost(cost1, cost2, costBoth, need1, need2);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
