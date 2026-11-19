// Created by oportunitas at 2026/11/19 13:22
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-score-by-changing-two-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 37.9MB/41th%)
        an amazingly clever solution for this problem is to sort the numbers first,
        and then we only choose to raise either the smallest 2 number to the 3rd smallest,
        lower the largest 2 number to the 3rd largest, or raise 1 lower 1.

        instead of sorting, we can do a partial sort to increase time performance
    */
    int minimizeSum(vector<int>& nums) {
        array<int, 3> min_nums; ranges::partial_sort_copy(nums, min_nums);
        array<int, 3> max_nums; ranges::partial_sort_copy(nums, max_nums, greater{});
        return min({
            max_nums[2] - min_nums[0], max_nums[1] - min_nums[1], max_nums[0] - min_nums[2]
        });
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minimizeSum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
