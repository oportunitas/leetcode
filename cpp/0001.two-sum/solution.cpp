// Created by oportunitas at 2026/08/20 12:07
// leetgo: 1.4.18
// https://leetcode.cn/problems/two-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	// runtime-efficient solution, but memory-heavy
	vector<int> twoSum(vector<int>& nums, int target) {
		// here the map is ordered as {value, index}
		unordered_map<int, int> num_to_idx;
        for (auto [i, num0] : nums | views::enumerate) {
			if (auto it = num_to_idx.find((int)(target - num0)); it != num_to_idx.end()) {
				auto [num1, j] = *it;
				return {(int)i, (int)j};
			} else {
				num_to_idx[num0] = i;
			}
		}
		return {};
    }

	// // memory-efficient solution, but runtime-heavy
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for (auto i : views::iota(0uz, nums.size() - 1)) {
	// 		int num0 = nums[i];
	// 		for (auto [j, num1] : nums | views::drop(i + 1) | views::enumerate) {
	// 			// views::enumerate enumerates from 0, so we add (i + 1) to j to get 
	// 			// what j would be if the array was still intact
	// 			if (num0 + num1 == target) return {(int)(i), (int)((i + 1) + j)};
	// 		}
	// 	}
	// 	return {};
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int target = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.twoSum(nums, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
