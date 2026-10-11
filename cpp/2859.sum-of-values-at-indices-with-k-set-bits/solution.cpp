// Created by oportunitas at 2026/10/11 12:40
// leetgo: 1.4.18
// https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 25.8MB/79th%)
        should be self-explanatory, we use popcount to count the set bits
    */
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int result {0};
        for (const auto& [i, num] : nums | views::enumerate) {
            if (popcount((uint)i) == k) result += num;
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.sumIndicesWithKSetBits(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
