// Created by oportunitas at 2026/10/22 08:14
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 141.3MB/99th%)
        since we're only able to reverse the entire array, we first need to check 
        the drops and increases in the array.

        if the array is valid, and most of the numbers are increasing, there must
        only be at most 1 drop in the entire array (cyclic considered). otherwise
        if most are decreasing, there must be at most only 1 increase in the entire
        array (cyclic considered)

        we track the count of increase and decreases. if both gets past 1, the array
        is unrecoverable. if we have 1 of either (which must happen), we find out
        the minimum between:
            if array is increasing already: 
                between moving the faulty index left,
                or reversing, then moving, then reversing again (as such 2 + ...)
            if array is decreasing:
                between moving the faulty index left first then reversing,
                or reversing first then moving left
    */
    int minOperations(vector<int>& nums) {
        int increase_count {0}; int increase_idx {-1};
        int decrease_count {0}; int decrease_idx {-1};

        if (nums[0] > nums[nums.size()-1]) {
            increase_count += 1;
            increase_idx = 0;
        } else {
            decrease_count += 1;
            decrease_idx = 0;
        } for (int i {1}; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                increase_count += 1;
                increase_idx = i;
            } else {
                decrease_count += 1;
                decrease_idx = i;
            }

            if (increase_count > 1 && decrease_count > 1) {
                return -1;
            }
        }


        if (decrease_count == 1) {
            return min(decrease_idx, 2 + (int)(nums.size() - decrease_idx));
        } else /* increase_count == 1 */ {
            return 1 + min(increase_idx, (int)(nums.size() - increase_idx));
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minOperations(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
