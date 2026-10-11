// Created by oportunitas at 2026/10/11 09:17
// leetgo: 1.4.18
// https://leetcode.com/problems/sum-of-squares-of-special-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 40.2MB/42th%)
        we can do a straightforward loop here
    */
    int sumOfSquares(vector<int>& nums) {
        int sum {0};
        for (const auto n {nums.size()}; const auto& [i, num] : nums | views::enumerate) {
            if (n % (i + 1) == 0) {
                sum += (num * num);
            }
        } return sum;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.sumOfSquares(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
