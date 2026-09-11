// Created by oportunitas at 2026/09/11 13:58
// leetgo: 1.4.18
// https://leetcode.com/problems/count-good-cyclic-rotations/
// https://leetcode.com/contest/weekly-contest-518/problems/count-good-cyclic-rotations/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1

	   1212
	   12 = 3
	   21 = 3

	   12 = 3
	   21 = 3

	   idea #0 hit time limit. im guessing that there is an O(n) solution to this.


	   123456

	   123 = 6, + 4 - 1
	   234 = 9, + 5 - 4
	   345 = 12


	   123222
	   232221
	*/
	int countGoodRotations(vector<int>& nums) {
		unordered_map<int64_t, int64_t> sum;
		int64_t cache = 0;

		int64_t result = 0;
		for (int64_t i = 0; i < nums.size() / 2; ++i) {
			cache += nums[i];
		}

		for (int64_t i = 0; i < nums.size(); ++i) {
			println("sum: {}", cache);
			if (sum.contains(i % (nums.size() / 2))) {
				if (sum[i % (nums.size() / 2)] != cache) result += 1;
			}
			sum[i % (nums.size() / 2)] = cache;
			cache = cache - nums[(i) % nums.size()] + nums[((nums.size() / 2) + i) % nums.size()];
		} return result;
	}


	// /* idea #0
	// 	123456

	// 	123 = 6
	// 	234 = 9
	// 	345 = 12

	// 	456	= 15
	// 	561 = 12
	// 	612 = 9

	// 	we can just find out whereever the pair is the same, and not include that in
	// 	the total. and also we dont need to loop through the entire array, just half is fine
	// */
    // int countGoodRotations(vector<int>& nums) {
	// 	int result {0};
    //     for (int i {0}; i < nums.size() / 2; ++i) {
	// 		int64_t cache = 0;
	// 		for (int j = 0; j < nums.size() / 2; ++j) {
	// 			// print("{},", nums[(i + j) % nums.size()]);
	// 			cache += nums[(i + j) % nums.size()];
	// 		}
	// 		for (int j = nums.size() / 2; j < nums.size(); ++j) {
	// 			// print("{},", nums[(i + j) % nums.size()]);
	// 			cache -= nums[(i + j) % nums.size()];
	// 		} 
	// 		// print("\n");
	// 		if (cache != 0) {
	// 			result += 1;
	// 		}
	// 	} return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countGoodRotations(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
