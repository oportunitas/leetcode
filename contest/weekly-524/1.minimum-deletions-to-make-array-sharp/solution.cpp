// Created by oportunitas at 2026/10/18 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-deletions-to-make-array-sharp/
// https://leetcode.com/contest/weekly-contest-524/problems/minimum-deletions-to-make-array-sharp/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /*
        non-zero xor just means that the numbers are different.
        thus we remove the amount of same numbers in the array
    */
    int minDeletions(vector<int>& nums) {
        int count {0};
        for (int i {1}; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                count ++;
            }
        } return count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minDeletions(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
