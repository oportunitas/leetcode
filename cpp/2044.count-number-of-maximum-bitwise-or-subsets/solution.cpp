// Created by oportunitas at 2026/09/07 12:25
// leetgo: 1.4.18
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1
		idea #0 works but its very slow. i think the general approach is correct
		but we just need to remove some unnecessary calculations, since in idea 0's deliberation,
		we can see that there are unnecessary additions/efforts at populating the total options
		array. lets try to work on this slowly but backwards and see if we can find patterns

			[001, 100, 101, 001, 100]
		begin:
			000  001  010  011  100  101
			     000  000  000  000  000
		001     
			000  001  010  011  100  101
     
			     000  000  000  000  000
			     001  000  000  000  000 +
			     001  000  000  000  000 =
		100     
			000  001  010  011  100  101
     
			     001  000  000  000  000
			     000  000  000  001  001 +
			     001  000  000  001  001
		101     
			000  001  010  011  100  101
     
			     001  000  000  001  001
			     000  000  000  000  100 +
			     001  000  000  001  100
		001     
			000  001  010  011  100  101
			     
			     001  000  000  001  100
			     001  000  000  000  101 +
				 001  000  000  001 1001

		001  000  000  000  000
		000  000  000  001  001
		000  000  000  000  100
		001  000  000  000  101

		hmm, no significant pattern showed up. 

		seems like we need to explore recursion nonetheless. lets find a way to do something similar to #idea 0 but with recursion. we need to have a stop point for recursion, so
		we need to find the max number first

		[3, 2, 1, 5], max = 6
		(result_count index, nums index)
         3
         3  2
         3  2  1
         3  2  1  5 x
         3  2     5 x
         3     1
         3     1  5 x
         3        5 x
            2
            2  1
            2  1  5 x
            2     5 x
               1
               1  5
                  5
        
        3
          2
            1
              5
            1 5
          2 1
          2   5 x
          2 1 5 x
        3 2
        3   1
        3     5 x
        3   1 5 x
        3 2 1
        3 2   5 x
        3 2 1 5 x

        3 2 1 5 x
        3 2 1 
        3 2   5 x
        3 2
        3   1 5 x
        3   1 
        3     5 x
        3
          2 1 5 x
          2 1 
          2   5 x
          2
            1 5
            1 
              5
        huh, weird pattern

        3 2 1 5 x
        3 2   5 x
        3 2 1
        3   1 5 x
        3     5 x
        3   1
        3 2
          2 1 5 x
          2   5 x
          2 1
            1 5
              5
            1
          2
        3

        an interesting pattern emerges in the above recursion deliberation, ones
        that start with 1st num has 4 total cases, one that start with 2nd num has 2 total cases
        (power of 2 correlation).

        2 3 1 5 x
        2 3 1 
        2 3   5 x
        2 3
        2   1 5 x
        2   1 
        2     5 x
        2
          3 1 5 x
          3 1 
          3   5 x
          3
            1 5
            1 
              5

        5 1 2 3 x
        5 1 2   x
        5 1   3 x
        5 1
        5   2 3 x
        5   2   x
        5     3 x
        5
          1 2 3 
          1 2 
          1   3 
          1
            2 3
            2 
              3

        nevermind then, this pattern doesnt seem to persist when we change the numbers around.
	*/
	int countMaxOrSubsets(vector<int>& nums) {
		auto final_max {[&nums] () {int _ {0}; for (auto num : nums) _ |= num; return _;} ()};
		vector<int> result_count (1 << 17, 0); result_count[0] = 1;

		for (int i = 0; i < nums.size(); ++i) {
			if (((nums[i] & final_max) ^ nums[i]) != 0) continue;
			for (int j = final_max; j >= 0; --j) {
				if (((j & final_max) ^ j) != 0) continue;
				result_count[j | nums[i]] += result_count[j];
			}
		} return result_count[final_max];
	} 

	// /* idea #0 (124ms/11th% | 75.8MB/13th%)
	// 	lets try to find a dynamic programming approach for this.
	// 	since or is both commutative and associative, we can replace it with addition
	// 	to find more obvious patterns.

	// 	lets use example 3 as an option:
	// 		[3, 2, 1, 5]
	// 	instead of finding max, lets try to find 8 to mimic the pattern of the problem.
	// 		[3, 2, 1, 5]

	// 	lets try to iterate over the array to find patterns
	// 		01 02 03 04 05 06 07 08 09 10 11 | total options
	// 		00 00 00 00 00 00 00 00 00 00 00 | result count
	// 	encounter 3
	// 		01 02 03 04 05 06 07 08 09 10 11 | total options
	// 		00 00 01 00 00 00 00 00 00 00 00 | result count
	// 	encounter 2. by this point, alongside adding 2, we add to 5 also since 
	// 	there's an option to add 3 to 2 to get 5. we can add the value of option 3 to
	// 	options 5 to do this
	// 		01 02 03 04 05 06 07 08 09 10 11 | total options
	// 		00 01 01 00 01 00 00 00 00 00 00 | result count
	// 	encounter 1. we should do the same
	// 		01 02 03 04 05 06 07 08 09 10 11 | total options
	// 		01 02 02 01 01 01 00 00 00 00 00 | result count
	// 	encounter 5. do the same
	// 		01 02 03 04 05 06 07 08 09 10 11 | total options
	// 		01 02 02 01 02 02 02 02 01 01 01 | result count
	// 	as such, we can find out the amount of subsets for each resulting value! nice.
	// 	we can do if elses for this implementation, but by simply using an array
	// 	with the 0th index with value 0, we can just define the problem as a loop like this:
	// 		(iterate over 'total options' backwards, starting from max_so_far):
	// 			'result count of the sum of the current number and the current total option' += 1
		
	// 	perhaps we can do the same thing with or? lets try
	// */
    // int countMaxOrSubsets(vector<int>& nums) {
	// 	vector<int> result_count (1 << 17, 0); result_count[0] = 1;
	// 	int max_so_far = 0;

	// 	for (int i = 0; i < nums.size(); ++i) {
	// 		for (int j = max_so_far; j >= 0; --j) {
	// 			result_count[j | nums[i]] += result_count[j];
	// 		} max_so_far |= nums[i];
	// 	} return result_count[max_so_far];
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countMaxOrSubsets(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
