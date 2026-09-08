// Created by oportunitas at 2026/09/08 16:21
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1 (0ms/100th% | 27.6MB/77th%)
		lets explore the number by its digits sum, ascending. perhaps we can find a pattern

		1, 2, 3, 4, 5, 6, 7, 8, 9

		10, 
		20, 11
		30, 21, 12
		40, 31, 22, 13
		50, 41, 32, 23, 14,
		60, 51, 42, 33, 24, 15,
		70, 61, 52, 43, 34, 25, 16,
		80, 71, 62, 53, 44, 35, 26, 17
		90, 81, 72, 63, 54, 45, 36, 27, 19

		going down always results in a bigger number
		going right always results in a smaller number

		lets visualize this on a 2d axis

		9|  9   10   11
		 |
		8|  8    9   10
         |
		7|  7    8    9
         |
		6|  6    7    8
         |
		5|  5    6    7
         |
		4|  4    5    6
         |
		3|  3    4    5
         |
		2|  2    3    4    5    6    7    8    9   10   11
         |
		1|  1    2    3    4    5    6    7    8    9   10
         |
		0|  0    1    2    3    4    5    6    7    8    9
		 |__________________________________________________
		+   0    1    2    3    4    5    6    7    8    9

		here, the digit sum is the manhattan distance from the origin.

		if we were to use coordinates as x and y to represent the digits of a number:
			10 -> [1, 0]
			13 -> [1, 3]
		as [x, y]

		we can find the manhattan distance by:
			dist = x + y

		and we can find the actual value of the number back by:
			val = 10x + y

		since the actual numbers are going to be between 1 and 10000, we can represent them
		as 5-dimensional coordinates:

			[v, w, x, y, z]
			dist = v + w + x + y + z
			val = 10000v + 1000w + 100x + 10y + 1z

		hmm, there's an interesting observation here. while the actual value of val cant be
		directly used to create an equation strictly between strict and val, we're using int
		representations! this means:
			val / 10
				which would mathematicaly result in:
			1000v + 100w + 10x + y + z / 10
				will actually result in:
			1000v + 100w + 10x + y
				instead! this is because in integer representation, any number behind the decimal
				dot is discarded. and since we know that v/w/x/y/z is always between 0 and 9,
				dividing them by 10 always results in a number less than 0.
		excellent! we can actually make a closed-form result by exploiting the int number
		representation

					dist  =       v +      w +     x +    y +  z
					-val  = -10000v + -1000w + -100x + -10y + -z
						   --------------------------------------
					      =  -9999v +  -999w +  -99x +  -9y
			   (9/10)val  =   9000v +   900w +   90x +   9y
			               --------------------------------------
						      -999v +   -99w +   -9x 
			(9/100)val    =    900v +    90w +    9x
				           --------------------------------------
						       -99v +    -9w
			(9/1000)val   =     90v +     9w
			               --------------------------------------
						        -9v 
			(9/10000)val  =      9v
			               --------------------------------------
						   0
		
		so, we can find out that:'
			0 = dist - val + (9/10)val + (9/100)val + (9/1000)val + (9/10000)val
		(we cant group vals to a single number since we're exploiting int representation along
		the way)
			0 = dist - val + (9/10)val + (9/100)val + (9/1000)val + (9/10000)val
			-dist = -val + (9/10)val + (9/100)val + (9/1000)val + (9/10000)val
			dist = val - ((9/10)val + (9/100)val + (9/1000)val + (9/10000)val)
		very nice! lets try this equation.
		
	*/
    int minElement(vector<int>& nums) {
		int min_sum {INT32_MAX};

		for (auto num : nums) {
			// println(
			// 	"{} {} {} {} {}", 
			// 	num, ((num/10)*9), ((num/100)*9), ((num/1000)*9), ((num/10000)*9)
			// );
			int cur_sum = num - ((num/10)*9) - ((num/100)*9) - ((num/1000)*9) - ((num/10000)*9);
			// println("cur sum: {}\n\n", cur_sum);

			min_sum = min(min_sum, cur_sum);
		}
		return min_sum;
    }

	// /* idea #0 (3ms/10th% | 28.8MB/5th%)
	// 	the most straightforward answer is to find the sum of the digits for each number
	// 	in the nums array. this results in O(n * avg_nums_digit_count) time though.
	// 	memoization might help but not a lot for max array size of 100, perhaps even
	// 	worsen time complexity, even, due to the added operations.

	// 	lets slightly over-engineer a bit, then we can lean the code down later.
	// */
    // int minElement(vector<int>& nums) {
    //     unordered_map<int, int> digit_sum {};
	// 	int min_sum {INT32_MAX};

	// 	for (auto num : nums) {
	// 		if (digit_sum[num] >= min_sum) continue;
	// 		int cur_sum = 0; int _num = num;

	// 		while (_num > 0) {
	// 			if (cur_sum >= min_sum) break;
	// 			cur_sum += _num % 10;
	// 			_num /= 10;
	// 		}

	// 		digit_sum[num] = cur_sum;
	// 		min_sum = min(min_sum, cur_sum);
	// 	}
	// 	return min_sum;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minElement(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
