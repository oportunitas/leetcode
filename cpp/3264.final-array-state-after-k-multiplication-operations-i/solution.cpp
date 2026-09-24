// Created by oportunitas at 2026/09/24 18:47
// leetgo: 1.4.18
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 27MB/90th%)
        for large arrays/operations, the best way is to sort the array first (remembering
        the original indeces of each), then we multiply the first k numbers, or directly 
        multiply by having the sorted array point us to the positions of the original array.

        however, max k is 10, so i believe we have no need.
    */
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i {0}; i < k; ++i) {
            array<int, 2> min_num {-1, INT_MAX};
            for (const auto& [j, num] : nums | views::enumerate) {
                if (num < min_num[1]) {
                    min_num[0] = j;
                    min_num[1] = num;
                }
            } nums[min_num[0]] *= multiplier;
        } return nums;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);
		int multiplier = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.getFinalState(nums, k, multiplier);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
