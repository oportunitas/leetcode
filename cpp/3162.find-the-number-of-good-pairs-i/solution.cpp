// Created by oportunitas at 2026/10/03 13:08
// leetgo: 1.4.18
// https://leetcode.com/problems/find-the-number-of-good-pairs-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 42.2MB/78th%)
        we can use views::cartesian_product to create a flattened list of all possible pair
        combinations between 2 vectors
    */
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        return ranges::count_if(
            views::cartesian_product(nums1, nums2), 
            [&k] (const auto& pair) {
                const auto& [num1, num2] = pair;
                return ((num1 % (k * num2)) == 0);
            }
        );
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums1 = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> nums2 = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.numberOfPairs(nums1, nums2, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
