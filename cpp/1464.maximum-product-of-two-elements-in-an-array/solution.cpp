// Created by oportunitas at 2026/10/27 10:18
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 13.3MB/99th%)
        we keep track of the 2 maximum values and multiply them in the end
    */
    int maxProduct(vector<int>& nums) {
        pair<int, int> maxes {-1, -1};
        for (const auto& num : nums) {
            if (num >= maxes.second) {
                maxes.first = maxes.second;
                maxes.second = num;
            } else if (num > maxes.first && num < maxes.second) {
                maxes.first = num;
            }
        } return (maxes.first - 1) * (maxes.second - 1);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxProduct(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
