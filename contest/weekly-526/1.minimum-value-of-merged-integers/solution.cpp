// Created by oportunitas at 2026/11/01 09:42
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-value-of-merged-integers/
// https://leetcode.com/contest/weekly-contest-526/problems/minimum-value-of-merged-integers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        uint64_t min_val {UINT64_MAX};
        for (size_t i {1}; i < nums.size(); i += 2) {
            string cur {};
            cur.append(to_string(nums[i-1]));
            cur.append(to_string(nums[i]));
            min_val = min(min_val, (uint64_t)stoi(cur));
        } return min_val;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minMergedInteger(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
