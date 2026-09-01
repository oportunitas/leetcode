// Created by oportunitas at 2026/09/01 16:47
// leetgo: 1.4.18
// https://leetcode.com/problems/partition-array-according-to-given-pivot/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #1
		idea #0 is more obvious, but perhaps we can make it more performant by:
			instead of using 3 preallocated huge vectors, we create only 1 with size of nums.size()
			then, (this might make runtime worse), we loop over nums 2 times:
				once to find less numbers, and count the amount of equal numbers
				then once again to find more numbers
	*/
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		auto result {[&nums] () {vector<int> _; _.reserve(nums.size()); return _;} ()};
		int same_count = 0;
		for (auto num : nums) {
			if (num < pivot) result.push_back(num);
			if (num == pivot) same_count += 1;
		} while (same_count--) {
			result.push_back(pivot);
		} for (auto num : nums) {
			if (num > pivot) result.push_back(num);
		} return result;
	}

	// /*idea #0 (3ms/139.58MB)
	// 	this might not be the most memory efficient but it's the most straightforward for me (we'll improve later):
	// 		create 3 arrays:
	// 			one to store less than pivot;
	// 			one to store equal to pivot;
	// 			one to store bigger than pivot;
	// 		we populate the arrays by looping through nums. this will preserve the ordering within each array.
	// */
    // vector<int> pivotArray(vector<int>& nums, int pivot) {
	// 	auto make_vec {[] () {vector<int> _; _.reserve(100000); return _;}};
	// 	auto [less, same, more] {tuple{make_vec(), make_vec(), make_vec()}};
		
	// 	for (auto num : nums) {
	// 		if (num < pivot) {
	// 			less.push_back(num);
	// 		} else if (num == pivot) {
	// 			same.push_back(num);
	// 		} else {
	// 			more.push_back(num);
	// 		}
	// 	}

	// 	nums.clear();
	// 	nums.insert(nums.end(), less.begin(), less.end());
	// 	nums.insert(nums.end(), same.begin(), same.end());
	// 	nums.insert(nums.end(), more.begin(), more.end());

	// 	return nums;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int pivot = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.pivotArray(nums, pivot);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
