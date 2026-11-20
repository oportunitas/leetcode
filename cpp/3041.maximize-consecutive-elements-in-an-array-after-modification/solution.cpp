// Created by oportunitas at 2026/11/20 13:16
// leetgo: 1.4.18
// https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (33ms/97th% | 75MB/100th%)
        idea #0 works, and its really elegant. lets now optimize.

        since the array is sorted, we dont really need to consider
        but the biggest 2 values (last number & last number + 1)
        at any point in the loop. this way we dont need to create
        the dp array, which might be memory and runtime heavy.
    */

    int maxSelectedElements(vector<int>& nums) {
        ranges::sort(nums);
        //                 dp[i]        dp[i+1]        i
        int dpmax {1}; int dpi {1}; int dpip1 {1}; int i {-2};
        for (const auto& num : nums) {
            if (num - i == 0) {
                // we can include this number but must increase by 1
                dpip1 = dpi + 1; 
            } else if (num - i == 1) {
                // this number can be put into dp[i] by adding 1
                dpi += 1;
                // or this number can be put into dp[i+1] as is
                dpip1 += 1;
            } else if (num - i == 2) {
                // we can include this number but must increase by 1
                dpi = dpip1 + 1;

                // then dp[i+1] gets to 1 since we restart from this number
                dpip1 = 1;
            } else {
                // this number cant be put anywhere, restart counting
                dpi = 1; dpip1 = 1;
            } 
            
            dpmax = ranges::max({dpmax, dpi, dpip1});
            i = num;
        }

        return dpmax;
    }

    // /* idea #0 (60ms/84th% | 107.4MB/71th%)
    //     this is a very interesting dp problem.

    //     lets sort the numbers first. this way, we traverse the array
    //     as the numbers increase in size

    //     at any point in the array, we can either choose to pick this
    //     number into a sequence or skip it.

    //     say we encountered the number 5. this number can either stay
    //     as 5 and be appended to whatever sequence ends with 4, or
    //     it can be increased by 1 to 6 and be appended to whatever sequence
    //     ends with 5.

    //     we can create a vector to store the length of the sequence ending in
    //     a value. then, at the end, we can get the max value in this vector
    //     as the return value.
    // */
    // int maxSelectedElements(vector<int>& nums) {
    //     ranges::sort(nums);

    //     vector<int> dp (nums.back() + 2, 0);
    //     for (const auto& num : nums) {
    //         // its important that we set dp[num+1] first, since the value
    //         // of dp[num+1] depends on dp[num]
    //         dp[num+1] = dp[num] + 1;
    //         dp[num] = dp[num-1] + 1;
    //     } return ranges::max(dp);
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxSelectedElements(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
