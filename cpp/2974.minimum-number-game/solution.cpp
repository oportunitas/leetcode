// Created by oportunitas at 2026/10/15 09:31
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-number-game/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 28MB/93th%)
        [6, 5, 4, 3, 2, 1]
        [2, 1, 4, 3, 6, 5]    
        [1, 2, 3, 4, 5, 6]

        we can sort first, then exchange every 2 values. this might not be
        100% optimal, but lets try
    */
    vector<int> numberGame(vector<int>& nums) {
        ranges::sort(nums);
        for (int i {0}; i < (nums.size() - 1); i += 2) {
            swap(nums[i], nums[i + 1]);
        } return nums;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.numberGame(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
