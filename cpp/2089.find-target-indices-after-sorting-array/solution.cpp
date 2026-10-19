// Created by oportunitas at 2026/10/19 08:17
// leetgo: 1.4.18
// https://leetcode.com/problems/find-target-indices-after-sorting-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 15.1MB/86th%)
        instead of sorting the array first, we can count the number of nums
        that are less than target, while also keeping track of nums equal to target.
        the index of the numbers in the sorted array that is equal to target necessarily
        starts after the last number that's smaller than it.
    */
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less_count {0};
        int same_count {0};
        for (const auto& num : nums) {
            if (num < target) {
                less_count += 1;
            } else if (num == target) {
                same_count += 1;
            }
        }

        vector<int> result;
        for (int i {less_count}; i < less_count + same_count; ++i) {
            result.push_back(i);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int target = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.targetIndices(nums, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
