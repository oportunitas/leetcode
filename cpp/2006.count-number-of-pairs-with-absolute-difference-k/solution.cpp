// Created by oportunitas at 2026/10/15 10:46
// leetgo: 1.4.18
// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 16.1MB/49th%)
        we store a count of every number, add by that instead, making the process
        only a single pass instead of nested pass (o(n^2)->o(n))
    */
    int countKDifference(vector<int>& nums, int k) {
        int result {0};
        vector<int> count(101, 0);
        for (const auto& num : nums) {
            if (num + k <= 100) result += count[num + k];
            if (num - k >= 0) result += count[num - k];
            count[num] += 1;
        } return result;
    }

    // /* idea #0 (3ms/57th% | 15.8MB/100th%)
    //     we code verbatim
    // */
    // int countKDifference(vector<int>& nums, int k) {
    //     int count {0};
    //     for (int i {0}; i < nums.size() - 1; ++i) {
    //         for (int j {i + 1}; j < nums.size(); ++j) {
    //             if (abs(nums[i] - nums[j]) == k) count++;
    //         }
    //     } return count;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.countKDifference(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
