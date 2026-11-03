// Created by oportunitas at 2026/11/02 15:05
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 15.6MB/97th%)
        slight mixup: we're supposed to find the median, not mean.
        to minimize the amount of "travels" every index needs to go, we would need to find
        a value that is in the middle of all the values.
    */
    int minMoves2(vector<int>& nums) {
        auto med {nums.begin() + (nums.size() / 2)};
        ranges::nth_element(nums, med);
        
        int ans {0};
        for (const auto& num : nums) {
            ans += abs(num - *med);
        } return ans;
    }

    // /* idea #0 (wrong answer)
    //     if we were framing this problem as:
    //         if the numbers were on a 2d graph, the output is the minimum integral
    //         of the graph against an x-axis line.
    //     which basically means that the x axis is the average value of the y values.

    //     so we find the average first, then we add up the differences.
    // */
    // int minMoves2(vector<int>& nums) {
    //     int avg {(int)round(ranges::fold_left(nums, 0.0, plus<double>{}) / (double)nums.size())};
        
    //     int ans {0};
    //     for (const auto& num : nums) {
    //         ans += abs(num - avg);
    //     } return ans;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minMoves2(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
