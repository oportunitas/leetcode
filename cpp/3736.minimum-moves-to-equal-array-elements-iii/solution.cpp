// Created by oportunitas at 2026/11/03 07:41
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 31.4MB/95th%)
        find max, sum differences
    */
    int minMoves(vector<int>& nums) {
        int max_num {ranges::max(nums)};
        
        int ans {0};
        for (const auto num : nums) {
            ans += max_num - num;
        } return ans;
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
