// Created by oportunitas at 2026/10/21 08:47
// leetgo: 1.4.18
// https://leetcode.com/problems/count-partitions-with-even-sum-difference/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public: 
    /* idea #1 (0ms/100th% | 22.6MB/23th%)
        we can do the following ramanujan-esque deduction from idea #0 to get
        an optimized approach:

        when we try to find the 'count' variable, we do this for each instance:
        (given s = nums[0]+nums[1]+...+nums[n-1], and p = nums[:i]):
            count increases by 1 if s - 2p is even (s - 2p = 2n).
            but if s - 2p is odd (s - 2p = 2n + 1), then the count does not increase.
        
        if s - 2p is equal to 2n:
            s - 2p = 2n
            s      = 2n + 2p
            s      = 2(n + p)
            s      = 2n
        then s itself must be an even number.

        if s - 2p is equal to 2n + 1:
            s     = 2n + 1
            s     = 2n + 2p + 1
            s     = 2(n + p) + 1
            s     = 2n + 1
        then s itself must be an odd number.

        notice that in both cases, the value of p itself doesnt matter in finding out
        if s is even or odd. as such it would not matter also in finding whether s-2p
        is even or odd. (we're multiplying p by 2 anyway in each for loop, whatever
        p is, 2p will always be even, and as such we only need to care on s's status)

        so the main concern we have is whether the total of s is even or odd.
        we can use bitwise xor to find this (last bit 1 always mean odd number).
    */
    int countPartitions(vector<int>& nums) {
        bool last_bit {0};
        for (const auto& num : nums) { last_bit ^= num & 1; };
        return last_bit ? 0 : nums.size() - 1;
    }

    // /* idea #0 (0ms/100th% | 22.2MB/98th%)
    //     we precompute running sums, then we just subtract.
    //     process time complexity is simply O(2*n)
    // */
    // int countPartitions(vector<int>& nums) {
    //     for (int i {1}; i < nums.size(); ++i) {
    //         nums[i] = nums[i - 1] + nums[i];
    //     } 
    //     // println("{}", nums);

    //     int count {0};
    //     for (int i {0}; i < nums.size() - 1; ++i) {
    //         if ((nums[nums.size() - 1] - 2 * (nums[i])) % 2 == 0) count++;
    //     }

    //     return count;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countPartitions(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
