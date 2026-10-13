// Created by oportunitas at 2026/10/13 07:13
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-alternating-sum-of-squares/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 175.9MB/90th%)
        we should only need to sort the values, add the first (n / 2)elements, 
        subtract the last n / 2 elements. if odd, add first (n / 2) + 1 elements instead
        n = 3

        0 1 2
        + - +
        + + -

        n = 4
        0 1 2 3
        + - + -
        + + - - 

        0 1 2 3 4
        + - + - +
        + + + - -

        3 2 1 0
        9 4 1 0, 9 - 4 + 1 - 0 = 6
        
        0 3 1 2
        0 9 1 4, 0 - 9 + 1 - 4 = -12

        although, instead of sorting the entire array altogether, since we only need to partition
        the array to 2, with numbers in the left bigger than numbers in the right,
        we can do quickselect (a part of what one does when doing quicksort) instead!

        in c++, we can do quickselect by using std::nth_element
    */
    long long maxAlternatingSum(vector<int>& nums) {
        int pivot_idx = (nums.size() - 1) / 2; // also is the last positive num
        ranges::nth_element(nums, nums.begin() + pivot_idx, greater<>{}, [] (const int& num) {
            return abs(int64_t{num}); // project to int64_t to prevent overflow on abs(INT_MIN)
        });

        int64_t pos_sum {transform_reduce(
            nums.begin(), nums.begin() + pivot_idx + 1,
            int64_t{0}, plus<>{}, [] (const int& num) { return int64_t{num} * int64_t{num}; }
        )};
        int64_t neg_sum {transform_reduce(
            nums.begin() + pivot_idx + 1, nums.end(),
            int64_t{0}, plus<>{}, [] (const int& num) { return int64_t{num} * int64_t{num}; }
        )};
        
        return pos_sum - neg_sum;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxAlternatingSum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
