// Created by oportunitas at 2026/10/23 17:00
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (100ms/74th% | 92.8MB/91th%)
        for each of the bits in k, say:
            00100101011
        this means that if the array is already correct, any 1 means that
        there's an odd number of 1s down that column, vice versa, any 0 means that
        there's an even number of 1s down that column

        we can try to do xor through the entire array first (as n), then:
            wherever the bit in k is not the same as n, we need one more 1 bit
        notice that we're finding out where n and k differs, which is just xor.

        we xor and count set count
    */
    int minOperations(vector<int>& nums, int k) {
        for (const auto& num : nums) {
            k ^= num;
        } return popcount((uint)k);
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
