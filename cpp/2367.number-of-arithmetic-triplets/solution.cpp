// Created by oportunitas at 2026/10/14 11:04
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-arithmetic-triplets/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 12MB/32th%)
        solve verbatim
    */
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> numsset;
        for (const auto& num : nums) {
            numsset.insert(num);
        }

        int count {0};
        for (const auto& num : numsset) {
            if (numsset.contains(num - diff) && numsset.contains(num - diff - diff)) {
                count += 1;
            }
        } return count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int diff = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.arithmeticTriplets(nums, diff);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
