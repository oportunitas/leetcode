// Created by oportunitas at 2026/10/23 10:36
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-k-to-sort-a-permutation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 152.6MB/92th%)
        000 000
        001 011 x
        010 010
        011 001 x


        000 000
        001 001
        010 011 x
        011 010 x

        000 011 x
        001 010 x
        010 001 x
        011 000 x

        lets try to use this pattern: we and all the numbers that are not correct.
    */
    int sortPermutation(vector<int>& nums) {
        int32_t k {-1}; // all 1s
        for (
            int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) k &= nums[i];
        } //println("k: {}", k);

        return max(0, k);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.sortPermutation(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
