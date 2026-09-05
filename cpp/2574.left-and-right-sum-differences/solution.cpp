// Created by oportunitas at 2026/09/05 14:08
// leetgo: 1.4.18
// https://leetcode.com/problems/left-and-right-sum-differences/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (0ms/100th% | 14.9MB/81th%)
		lets try the most obvious approach first:
			find the total of all numbers;
			we iterate linearly over the array, shifting the total value along the way
	*/
    vector<int> leftRightDifference(vector<int>& nums) {
        int64_t total {reduce(nums.begin(), nums.end(), int64_t{0}, plus<int64_t>())};
		vector<int> result (nums.size(), 0);

		for (int i {0}; i < nums.size(); ++i) {
			total -= nums[i];
			result[i] += abs(total);
			total -= nums[i];
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.leftRightDifference(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
