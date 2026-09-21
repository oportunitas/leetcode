// Created by oportunitas at 2026/09/21 12:20
// leetgo: 1.4.18
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 14.2MB/50th%)
		the most straightforward solution is to check the entire array every time. but this
		is time-exhausting.

		we can create a map, and then iterate over it, adding the count along the way.
	*/
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> counts (128, 0);
		for (auto&& num : nums) {
			counts[num + 1] += 1;
		}
		// println("{}", counts);

		for (int i = 1; i < counts.size(); ++i) {
			counts[i] += counts[i - 1];
		}
		// println("{}", counts);

		auto result {[&nums] () { vector<int> _; _.reserve(nums.size()); return _; } ()};
		for (auto&& num : nums) {
			result.push_back(counts[num]);
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.smallerNumbersThanCurrent(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
