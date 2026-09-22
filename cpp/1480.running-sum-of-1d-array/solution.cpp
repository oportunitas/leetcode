// Created by oportunitas at 2026/09/22 11:36
// leetgo: 1.4.18
// https://leetcode.com/problems/running-sum-of-1d-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 12.6MB/13th%)
		lets just do the most straightforward approach: adding along the way
	*/
    vector<int> runningSum(vector<int>& nums) {
		vector<int> result (nums.size(), 0);
		result[0] = nums[0];
		for (int i {1}; i < nums.size(); ++i) {
			result[i] = nums[i] + result[i - 1];
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.runningSum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
