// Created by oportunitas at 2026/11/12 10:48
// leetgo: 1.4.18
// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin


class Solution {
public:
    /* idea #0 (0ms/100th% | 27.6MB/100th%)
        my first idea was to set a boolean to switch between whether the current running subarray
        is increasing or decreasing. this can work and is slightly more memory efficient, but is
        hard to read and understand by human code readers. as such, at the cost of slight memory,
        we create 2 variables instead to store the size of the current running increasing subarray
        and the current running decreasing subarray, and at each loop check which one is the biggest
    */
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_len {1}; int inc_cur_len {1}; int dec_cur_len {1};
        for (const auto& [num1, num2] : nums | views::pairwise) {
            inc_cur_len = (num2 > num1) ? (inc_cur_len + 1) : 1;
            dec_cur_len = (num2 < num1) ? (dec_cur_len + 1) : 1;
            max_len = max({max_len, inc_cur_len, dec_cur_len});
        } return max_len;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.longestMonotonicSubarray(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
