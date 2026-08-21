// Created by oportunitas at 2026/08/21 08:47
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
		// we use std::reduce() here to prevent for loops and zen-ify the code
        uint_fast32_t total = reduce(nums.begin(), nums.end(), uint_fast32_t{0});
		uint_fast32_t remainder = total % k;

		// println("{}", remainder);
		
		return remainder;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minOperations(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
