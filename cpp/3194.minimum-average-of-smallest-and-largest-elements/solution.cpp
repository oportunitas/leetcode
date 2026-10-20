// Created by oportunitas at 2026/10/20 18:01
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 25.63MB/60th%)
         0  1  2  3  4  5  6   7
        [1, 2, 3, 3, 7, 8, 13, 15]
        we just find the value of the middle elements
    */
    double minimumAverage(vector<int>& nums) {
        ranges::sort(nums);
        double result {1000.0};
        for (int l = 0, r = nums.size() - 1; l < r; ++l, --r) {
            result = min(result, ((double)(nums[l] + nums[r]) / 2));
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minimumAverage(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
