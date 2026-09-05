// Created by oportunitas at 2026/09/05 13:26
// leetgo: 1.4.18
// https://leetcode.com/problems/concatenation-of-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (0ms/100th% | 17.18MB/16.16th%)
		we just enlarge the memory space allocation of nums, and then concat it
		to itself.
	*/
    vector<int> getConcatenation(vector<int>& nums) {
        nums.reserve(nums.size() * 2);
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};
// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.getConcatenation(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
