// Created by oportunitas at 2026/11/17 20:20
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (95ms/91th% | 15.6MB/35th%)
        i've slowly worked out the details on the problem and have unfortunately yet to arrive
        at a satisfactory solution that doesnt have an insane time complexity. for this problem,
        i'll humbly work my way to understand it through the public solutions

        the main idea behind the solution is generally straightforward: we first find the cost
        to change a certain substring to semi-palindrome, and then do dp to find out (since
        i like to use multiverse analogies for dp) to traverse from the beginning of the string,
        then prune any inefficient timelines along the way, and then return the optimum timeline
        when we get to the last index. we find the optimum timeline along each step by finding
        which is better between an iota (reverting the whole thing basically) and by continuing
        the previous dp/timeline 
    */
    int minimumChanges(string s, int k) {
        int n = ssize(s); int inf = INT_MAX / 2;

        // find the cost of changing s[i] -> s[j] a semi-palindrome
        vector cost(n + 1, vector(n + 1, inf));
        auto peel = [&](int i, int j, int d) {
            int changes = 0;
            for (; j - i > d; i += d, j -= d) {
                for (int t = 0; t < d; ++t) {
                    changes += s[i+t] != s[j-d+t];
                }
            } return changes;
        }; for (int d = 1; 2 * d <= n; ++d) {
            for (int length = 2 * d; length <= n; length += d) {
                for (int i = 0, j = length; j <= n; ++i, ++j) {
                    cost[i][j] = min(cost[i][j], peel(i, j, d));
                }
            }
        }

        // dynamic programming, dp is the fewest changes for any strings prefix up to the index
        vector dp(n + 1, inf); dp[0] = 0;
        auto extend = [&] (int j) {
            return ranges::min(views::iota(0, j - 1) | views::transform([&](int i) { 
                return dp[i] + cost[i][j]; 
            }));
        }; for (int pieces = 1; pieces < k; ++pieces) {
            vector next(n + 1, inf);
            for (int j = 2 * pieces; j <= n - 2 * (k - pieces); ++j) {
                next[j] = extend(j);
            } swap(dp, next);
        } return extend(n);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minimumChanges(s, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
