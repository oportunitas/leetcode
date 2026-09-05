// Created by oportunitas at 2026/09/05 18:17
// leetgo: 1.4.18
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #2 (0ms/100th% | 10.1MB/90th%)
		idea #1 starts off strong, but im still sensing that there's an iterative solution ahead.
		its also generally good practice to avoid recursions if possible.

		lets look at the problem iteratively:

		[a, b, c, d, e, f, g, ...]

		borrowing a concept from idea #0, the starting index of the result should be between 0 and 1
		since using indeces 2 or above to start just wastes money (since there's no negative)

		we therefore have two possibilities:
			 v  -  ?  ?  ?  ?  ?  ???
			[a, b, c, d, e, f, g, ...], lets say this is scenario X

			 -  v  -  ?  ?  ?  ?  ???
			[a, b, c, d, e, f, g, ...], lets say this is scenario Y
		
		the result should be the maximum between scenario X and Y

		now, for a twist: we can imagine ourselves in this scenario pair someway through the array!
		in this case, we assume that we already found the maximum number achievable for all
		houses to the left

			 !  !  !  !  !  v  -  ?  ?  ?  ?  ?  ???
			[., ., ., ., ., a, b, c, d, e, f, g, ...]

			 !  !  !  !  !  -  v  -  ?  ?  ?  ?  ???
			[., ., ., ., ., a, b, c, d, e, f, g, ...]
		
		in this case we already exhausted the previous houses and have found out some number A,
		so we are now just trying to find out between A + X and A + Y

		notice that this is the same process as with the beginning X/Y problem all over again! 
		therefore we can do the following process:

			find max between: 
				v  ?  ?  ?  ?  ?  ?  ???
				[a, b, c, d, e, f, g, ...],
				-  ?  ?  ?  ?  ?  ?  ???
				[a, b, c, d, e, f, g, ...],

			and then find max between:
				 !  v  ?  ?  ?  ?  ?  ???
				[a, b, c, d, e, f, g, ...],
				 !  -  ?  ?  ?  ?  ?  ???
				[a, b, c, d, e, f, g, ...],

			and so on (not exactly to detail, refer to rob() function body)
	*/
	int rob(vector<int>& nums) {
		// store the maximums for each scenario, 
		// lets use x as the scenario where we pick the first unadded number as to be added
		// y as the first unadded number to be skipped
		int x_max = 0;
		int y_max = 0;

		for (int cur_max = 0; auto num : nums) {
			/* 
				find max between these scenarios
					 !!!  !  !  !  !  v  ?  ?  ?  ?  ?  ?  ???
					[..., ., ., ., ., a, b, c, d, e, f, g, ...] (x_max + num) | X scenario

					 !!!  !  !  !  !  -  ?  ?  ?  ?  ?  ?  ???
					[..., ., ., ., ., a, b, c, d, e, f, g, ...] (y_max)       | Y scenario
			*/ cur_max = max(x_max + num, y_max);

			/*
				if we want to invoke scenario X on the next iteration, we can only do so
				under the assumption that we are invoking scenario Y in this iteration.
				as such, to even consider the X scenario on the next iteration,
				the next iteration's x_max should be equal to this iteration's y_max
			*/ x_max = y_max;

			/*
				we have 2 scenarios depending on whether cur_max is on the X or Y scenario.
				we can try to do an if-else statement to check whether a is skipped, but there's
				a better way to do this:

				if cur_max is (x_max + num), then the only option is to skip the
				next house (skip b in this case), thus cur_max is equivalent to the next
				iteration's y_max (since we can only choose the Y scenario in the next iteration). 

				if cur_max is (y_max), then we can choose on the next house to either skip or rob.

				if we look at the two above rules backwards, it can only mean that the next
				iteration's y_max is always this iteration's cur_max.
			*/ y_max = cur_max;

			/*
				another way to frame the changing of x_max and y_max is as follows:
					depending on what scenario we choose now (X or Y):
						the next scenario can choose Y whether we choose either X or Y now; BUT
						the next scenario cannot choose X if we're already choosing X now.
					as such, next iteration's scenario Y can freely use this iteration's 
					'maximum so far' value since it doesnt matter, but the X scenario can only
					use the previous iteration's 'maximum so far' value, which is stored in
					the maximum value for the Y scenario of this iteration
			*/
		}

		/*
			at first glance one might think that the most sensible return value is
			max(x_max, y_max), but one need to remember that x and y here means the scenario
			to be choosen at the next iteration of the loop. 

			as such, we can instead immediately return y_max, since y_max is already defined as
			whatever the maximum is so far (since this accomodated for a hypothetical continuation
			of the loop where one dont need to add anything anymore, which is the same in nature
			as the end of the loop)
		*/ return y_max;
	}


	// /* idea #1 (0ms/100th% | 10.7MB/47th%)
	// 	well this is kind of embarrassing, idea #0 completely neglects the fact
	// 	that f - g is always negative:
	// 		[2, 0, 0, 2] | Z

	// 		[2, 0, 1, 0] | X
	// 		[0, 0, 1, 0] | - (X - 2(f))
	// 		[0, 0, 0, 2] | + (Y - 1(g))
	// 	f - g is 2 - 1 here.

	// 	so, lets do a more traditional approach to the problem, even with potential
	// 	cost to runtime/memory performance:
	// 		we can do recursion here, to iterate through all subsets. 
	// 		it would be nice to also have memoization though, but for now lets use
	// 		brute force and see how good the performance is


	// 	on a side note, lets explore if there is still an O(N) solution:
	// 		1 2 3 1

	// 		1   3     4 (answer)
	// 		1     1   2
	// 		  2   1   3
	// 		    3     3

	// 		2 2 6 1
	// 		2 1 2 2



	// 		2  7  9  3  1

	// 		2     9     1       12 (answer)
	// 		2        3          5
	// 		2           1       3
	// 		   7     3          10
	// 		   7        1       8
	// 		      9     1       10
	// 			  9             9
	// 			     3          3
	// 				    1       1
			
	// 		6 14 27  9  5
	// 		3  2  3  3  4
	// 	still nothing revealed so far...

	// 	>>> post-submit note
	// 	the memoized recursion implementation works nicely at 0ms!
	// */
	// int rob(vector<int>& nums) {
	// 	vector<int> cache(nums.size(), -1);
	// 	auto best_rob {[&nums, &cache] (this auto& self, int check_index, int sum_so_far, int depth) -> int {
	// 		// for (auto i : views::iota(0, depth)) print("  ");
	// 		// println("i: {}, ssf: {}", check_index, sum_so_far);

	// 		if (cache[check_index] != -1) return cache[check_index] + sum_so_far;

	// 		int new_sum = nums[check_index];
	// 		for (int i = check_index + 2; i < nums.size(); ++i) {
	// 			new_sum = max(new_sum, self(i, nums[check_index], depth + 1));
	// 		} 
			
	// 		cache[check_index] = new_sum;
	// 		return cache[check_index] + sum_so_far;
	// 	}};

	// 	// println("---");

	// 	int result = 0;
	// 	for (int i = 0; i < nums.size(); ++i) {
	// 		result = max(result, best_rob(i, 0, 0));
	// 	}

	// 	return result;
	// }

	// /* idea #0 (Wrong Answer)
	// 	ideally there are only 2 options: rob every even index, or rob every odd index
		
	// 	the following is my reasoning:
	// 		lets describe the vector as following:
	// 			[a, b, c, d, e, f, ...]
	// 		we indicate the houses to rob as x, the houses to skip as -, if we 
	// 		were using either the odd indexed numbers only:
	// 			[-, x, -, x, -, x, ...], lets say the sum of this is X
	// 		or using either the even indexed numbers only:
	// 			[x, -, x, -, x, -, ...], lets say the sum of this is Y
			
	// 		there is an option to skip 2 houses instead of one house in a robbing session:
	// 			[x, -, -, x, -, x, ...] | Z
	// 		this instance specifically can be described as:
	// 			[x, -, x, -, x, -, ...] | + X
	// 			[-, -, x, -, x, -, ...] | - (X - some amount f)
	// 			[-, -, -, x, -, x, ...] | + (Y - some emount g)
	// 		or:
	// 			X - (X - some amount: f) + (Y - some amount: g)
	// 		   =X - X + f + Y - g
	// 		   =Y + f - g, we know that since Y is the part thats cut more, g > f
	// 		   Z = Y - h

	// 		in this case, we can analytically prove that Z is always smaller than Y.
	// 		while this on itself does not necesarrily prove that Z is smaller than X, 
	// 		we can flip the equation as eliminating Y:
	// 			[x, -, x, -, x, -, ...] + Y
	// 			[-, -, x, -, x, -, ...] - (Y - some amount f)
	// 			[-, -, -, x, -, x, ...] + (X - some amount g), g > f
	// 		and arrive at the same conclusion

	// 		as such, we only need to find the maximum between the options of:
	// 			sum of all odd index, and
	// 			sum of all even index.
	// */
    // int rob(vector<int>& nums) {
    //     auto odd_nums  = nums | views::drop(1) | views::stride(2);
	// 	auto even_nums = nums | views::stride(2);

	// 	return max(
	// 		reduce(odd_nums.begin(), odd_nums.end(), 0, plus<>()), 
	// 		reduce(even_nums.begin(), even_nums.end(), 0, plus<>())
	// 	);
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.rob(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
