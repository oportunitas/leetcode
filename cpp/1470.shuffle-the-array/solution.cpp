// Created by oportunitas at 2026/09/15 14:42
// leetgo: 1.4.18
// https://leetcode.com/problems/shuffle-the-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 13.4MB/82th%)
		we can try just looping
	*/
    vector<int> shuffle(vector<int>& nums, int n) {
        auto result {[&nums] () {vector<int> _; _.reserve(nums.size() + 1); return _;} ()};
		for (int i {0}; i < n; ++i) {
			result.push_back(nums[i]);
			result.push_back(nums[n + i]);
		}
		return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.shuffle(nums, n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
