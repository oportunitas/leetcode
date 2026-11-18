// Created by oportunitas at 2026/11/10 14:00
// leetgo: 1.4.18
// https://leetcode.com/problems/climbing-stairs-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (15ms/78th% | 169.2MB/100th%)
        lets optimize.
            at any point, we are only considering 3 timelines (i-1, i-2, i-3).
            therefore we can increase calculation efficiency by first storing
            the 3 timelines, then in each iteration directly compare those instead
            of expanding a vector.
    */
    int climbStairs(int n, vector<int>& costs) {
        //  i - 1      i - 2      i - 3
        int a = 0; int b = 0; int c = 0;

        for (const auto& [i, cost] : costs | views::enumerate) {
            // the three timeline branches that can get here
            int best_option = cost + min({a + 1, b + 4, c + 9});

            // shift by 1
            c = b; b = a; a = best_option;
        }

        return a;
    }

    // /* idea #0 (28ms/36th% | 187.1MB/16th%)
    //     this is a perfect exercise ground for dynamic programming.

    //     i like to view dynamic programming as a "multiverse" problem.

    //     at each stairstep, we either get there by getting from i-1, i-2, or i-3.
    //     we prune every timeline that is not optimal (between i-1, i-2, and i-3).

    //     to do this, we can just visit every moment in time (every step in the ladder),
    //     and find the minimum value of either getting there from (i-1, i-2, or i-3). 
    //     of course, in ladder step 1, we can only come from 0, so that's the only option
    //     in ladder step 2, we can only come from either 0 or 1, so we compare only 2.

    //     but for every other index, the idea is the exact same.
    // */
    // int climbStairs(int n, vector<int>& costs) {
    //     vector<int> best_timeline;
    //     for (const auto& [i, cost] : costs | views::enumerate) {
    //         // the three timeline branches that can get here
    //         int a = (i > 0 ? best_timeline[i-1] : 0) + 1 + cost;
    //         int b = (i > 1 ? best_timeline[i-2] : 0) + 4 + cost;
    //         int c = (i > 2 ? best_timeline[i-3] : 0) + 9 + cost;

    //         best_timeline.push_back(min(a, min(b, c)));
    //     }

    //     return best_timeline.back();
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		vector<int> costs = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.climbStairs(n, costs);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
