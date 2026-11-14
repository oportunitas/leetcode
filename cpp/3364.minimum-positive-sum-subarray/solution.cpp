// Created by oportunitas at 2026/11/14 11:37
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-positive-sum-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 30.3MB/12th%)
        +3 -2 +1 +4
         0 +3 +1 +2 +6

        lets first try to solve it using a more straightforward solution
    */
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> prefix_sum(nums.size() + 1);
        partial_sum(nums.begin(), nums.end(), prefix_sum.begin() + 1);

        int min_sum {INT_MAX};
        for (int diff = l; diff <= r; ++diff) {
            for (int i = 0; i + diff <= nums.size(); ++i) {
                int cur_sum = prefix_sum[i + diff] - prefix_sum[i];
                if (cur_sum > 0) min_sum = min(min_sum, cur_sum);
            }
        }

        return (min_sum == INT_MAX) ? (-1) : (min_sum);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int l = LeetCodeIO::deserialize<int>(cin);
		int r = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minimumSumSubarray(nums, l, r);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
