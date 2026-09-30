// Created by oportunitas at 2026/09/30 08:37
// leetgo: 1.4.18
// https://leetcode.com/problems/decompress-run-length-encoded-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 12.63MB/98th%)
        lets just use the most straightforward solution.
    */
    vector<int> decompressRLElist(vector<int>& nums) {
        auto result {[] () {vector<int> _; _.reserve(1 << 12); return _;} ()};
        for (int i {0}; i < nums.size(); i += 2) {
            for (int j {0}; j < nums[i]; ++j) {
                result.push_back(nums[i + 1]);
            }
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.decompressRLElist(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
