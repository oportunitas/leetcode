// Created by oportunitas at 2026/10/15 08:50
// leetgo: 1.4.18
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 24.5MB/100th%)
        lets do a more straightforward, but albeit i believe slower approach:
            - we keep track of whether a number already exists beforehand
            - in each loop, we go backwards
    */
    int sumCounts(vector<int>& nums) {
        bitset<101> already_exists;
        int result {0};
        for (int i {0}; i < nums.size(); ++i) {
            already_exists.reset();
            int distinct_count {0};
            for (int j {i}; j >= 0; --j) {
                if (!already_exists[nums[j]]) {
                    distinct_count += 1;
                } already_exists[nums[j]] = 1;
                result += (distinct_count * distinct_count);
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
		auto res = obj.sumCounts(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
