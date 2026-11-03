// Created by oportunitas at 2026/11/01 11:08
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 32MB/84th%)
        the trick behind the idea is to reverse the thinking: incrementing n-1 elements by 1
        in nature is the same as decrementing 1 element by 1.

        [1, 2, 3] [1, 2, 3]
        [2, 3, 3] [1, 2, 2]
        [3, 4, 3] [1, 2, 1]
        [4, 4, 4] [1, 1, 1]

        so we just need to find the minimum value, then find the difference between
        the minimum values and each element!
    */
    int minMoves(vector<int>& nums) {
        int min_val {ranges::min(nums)};
        int result {0};
        
        for (const auto& num : nums) {
            result += (num - min_val);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minMoves(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
