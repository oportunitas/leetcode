// Created by oportunitas at 2026/10/26 13:32
// leetgo: 1.4.18
// https://leetcode.com/problems/sum-of-variable-length-subarrays/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 26.3MB/100th%)
        we precompute running sum, then subtract (O(2*N) time)
    */
    int subarraySum(vector<int>& nums) {
        // precompute running sum
        for (int i {1}; i < nums.size(); ++i) {
            nums[i] = nums[i] + nums[i-1];
        } 
        // println("{}", nums);

        int sum {0};
        for (int i {0}; i < nums.size(); ++i) {
            int cur_num {i > 0 ? nums[i] - nums[i-1] : nums[i]};
            int start_i {max(0, i-cur_num) - 1};
            int start_n {start_i < 0 ? 0 : nums[start_i]};
            sum += (nums[i] - start_n);
        } 

        return sum;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.subarraySum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
