// Created by oportunitas at 2026/09/05 13:28
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-good-pairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /*idea #0 (0ms/100th% | 9.87MB/23.39th%)
        the obvious idea would have O(n log n) time complexity (iterate through the array in nested loops),
        there might be an O(n) solution though. 

        we can iterate to find the amount of each numbers, and then do (n + (n - 1) / 2)
    */
    int numIdenticalPairs(vector<int>& nums) {
        int result {0};
        vector<int> counts (101, 0);
        for (auto num : nums) {
            counts[num] += 1;
        } for (auto count : counts) {
            result += (count * (count - 1)) / 2;
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.numIdenticalPairs(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
