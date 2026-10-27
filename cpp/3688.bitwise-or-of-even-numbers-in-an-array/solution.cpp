// Created by oportunitas at 2026/10/27 10:24
// leetgo: 1.4.18
// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 24.4MB/91th%)
        solve verbatim
    */
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans {0};
        for (const auto& num : nums) {
            if (num % 2 == 0) {
                ans |= num;
            }
        } return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.evenNumberBitwiseORs(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
