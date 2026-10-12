// Created by oportunitas at 2026/10/12 07:07
// leetgo: 1.4.18
// https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (55ms/66th% | 94.9MB/8th%)
        11111111 -> 00000000
        00000000 -> 11111111

        10101010 -> 00000000
        01010101 -> 11111111

        if we have 2 numbers with alternating 0s and 1s:
            0101 -> 5  -> 5^2  -> 25
            1010 -> 10 -> 10^2 -> 100
        if we were to update these:
            0000 -> 0  -> 0^2  -> 0
            1111 -> 15 -> 15^2 -> 225
        the total will always be greater even in this case, let alone cases
        where the 'and' case still has remaining set bits.

        lets observe example 1 as a 2d array:
            0010
            0110
            0101
            1000
        a nice intuition here is that the operation the question is asking
        is visually representable as the 1 bits "falling down":
            11111111 -> 00000000
            00000000 -> 11111111

            10101010 -> 00000000
            01010101 -> 11111111

            01100011 -> 01000001
            11011001 -> 11111011
        see how the 1 bits look like they fell down from the top to the bottom

        this results in a very nice way of looking at the problem! since we have no limit
        as to the number of operations, we can definitely look at this problem as "beads"
        falling down "columns"
            0010 -> 0000
            0110 -> 0000
            0101 -> 0110
            1000 -> 1111
        when we want to maximize the sum, we take the k lowest levels.
        
        instead of manually iterating through the "gravity/beads falling simulation" by
        doing the process manually, we can instead precalculate the final state of the
        system, by counting the number of beads in each column. this effectively means
        storing a 1d array containing the count of set bits in every bit position.
    */
    int maxSum(vector<int>& nums, int k) {
        const int64_t base {1000000007};
        array<int, 32> count; ranges::fill(count, 0);
        vector<int64_t> final_nums(k, 0);

        // println("{}", nums);
        for (const auto& num : nums) {
            for (int bit_pos {0}; bit_pos < 32; ++bit_pos) {
                if ((num >> bit_pos) & 1 && count[bit_pos] < k) {
                    final_nums[count[bit_pos]] += (int64_t{1} << bit_pos);
                    count[bit_pos] += 1;
                }
            }
        }
        // println("{}", count);
        // println("{}", final_nums);

        int64_t sum {0};
        for (const auto& final_num : final_nums) {
            sum += final_num * final_num;
            sum %= base;
        } return (int)sum;

        // for (int cur_k {0}; cur_k < k; ++cur_k) {

        // }

        // int64_t sum {0};
        // for (int i {1}; i <= k; ++i) {
        //     sum += ((nums[nums.size() - i] * nums[nums.size() - i]) % base);
        // }
        // println("{}", nums);
        // println("sum: {}", sum);
    }   
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.maxSum(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
