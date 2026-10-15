// Created by oportunitas at 2026/10/15 10:18
// leetgo: 1.4.18
// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 19.4MB/21st%)
        we do verbatim
    */
    int differenceOfSum(vector<int>& nums) {
        int el_sum {0};
        int dig_sum {0};
        for (auto& num : nums | views::reverse) {
            el_sum += num;
            while (num > 0) {
                dig_sum += num % 10;
                num /= 10;
            }
        } return abs(el_sum - dig_sum);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.differenceOfSum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
