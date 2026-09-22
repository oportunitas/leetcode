// Created by oportunitas at 2026/09/22 07:50
// leetgo: 1.4.18
// https://leetcode.com/problems/find-x-value-of-array-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1
		i believe the main the logic behind idea #0 is correct, but i believe
		we're wasting time on unnecessary calculations.
		
	*/
    static vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
		vector<int> result (queries.size(), 0);
		array<int, 5> cur_res {{0}};
		for (auto&& [i, query] : queries | views::enumerate) {
			cur_res.fill(0);
			nums[query[0]] = query[1];

			int last_num = 1;
			for (int h {query[2]}; h < nums.size(); ++h) {
				const int num = nums[h];
				last_num = ((num % k) * (last_num % k)) % k;
				cur_res[last_num] += 1;
			} 

			result[i] = cur_res[query[3]];
			// println("res: {}", result);
		}

        return result;
    }

	// /* idea #0 (time limit exceeded)
	// 	lets start off from problem 3524's solution and build on it

	// 	3524's solution was for getting the count of remainder options. 

	// 	3524 asks for considering removing both prefix and suffix. this problem
	// 		already removes the prefix for us via query.

	// 		begin:
	// 			result so far: [0, 0, 0]
	// 			new          : [0, 0, 0]
	// 			new result   : [0, 0, 0]
	// 		receive 1 % 3 = 1 (0->0, 1->1, 2->2):
	// 			result so far: [0, 0, 0]
	// 			new          : [0, 1, 0]
	// 			new result   : [0, 1, 0]
	// 		receive 2 % 3 = 2 (0->0, 1->2, 2->1):
	// 			result so far: [0, 1, 0]
	// 			new          : [0, 0, 1]
	// 			new result   : [0, 1, 1]
	// 		receive 2 % 3 = 2 (0->0, 1->2, 2->1):
	// 			result so far: [0, 1, 1]
	// 			new          : [0, 0, 1]
	// 			new result   : [0, 2, 1]
	// 		receive 4 % 3 = 1 (0->0, 1->1, 2->2):
	// 			result so far: [0, 2, 1]
	// 			new          : [0, 1, 0]
	// 			new result   : [0, 3, 1]
	// 		receive 5 % 3 = 2 (0->0, 1->2, 2->1):
	// 			result so far: [0, 3, 1]
	// 			new          : [0, 0, 1]
	// 			new result   : [0, 3, 2]

	// 		what this essentially means is that when we move backwards in retrograde:
	// 		 	_<-
	// 		 	__<-
	// 		 	---<-

	// 		when we previously considered any new prefix cut, we now dont. this 
	// 		means that we no longer need from_prev array, just a from_prev
	// 		number (since there's no other option than to multiply onwards)
	// */
    // static vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
	// 	vector<int> result (queries.size(), 0);
	// 	array<int, 5> cur_res {{0}};
	// 	for (auto&& [i, query] : queries | views::enumerate) {
	// 		cur_res.fill(0);
	// 		nums[query[0]] = query[1];

	// 		int last_num = 1;
	// 		for (int h {query[2]}; h < nums.size(); ++h) {
	// 			const int num = nums[h];
	// 			last_num = ((num % k) * (last_num % k)) % k;
	// 			cur_res[last_num] += 1;
	// 		} 

	// 		result[i] = cur_res[query[3]];
	// 		// println("res: {}", result);
	// 	}

    //     return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);
		vector<vector<int>> queries = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.resultArray(nums, k, queries);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
