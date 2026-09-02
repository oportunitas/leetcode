// Created by oportunitas at 2026/09/02 12:26
// leetgo: 1.4.18
// https://leetcode.com/problems/compute-alternating-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (Runtime: 0ms/100th% | Memory: 32.7MB/11th%)
		lets start with the most obvious solution: iterating over the array, and adding/
		subtracting based on whether its index is odd/even
	*/
    int alternatingSum(vector<int>& nums) {
        int result = 0;
		for (auto [i, num] : nums | views::enumerate) {
			if (i % 2 == 0) {
				result += num;
			} else {
				result -= num;
			}
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.alternatingSum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
