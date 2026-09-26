// Created by oportunitas at 2026/09/26 19:31
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 24.8MB/80th%)
        just count numbers < k
    */
    int minOperations(vector<int>& nums, int k) {
        int result {0};
        for (const auto& num : nums) {
            result += (num < k);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minOperations(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
