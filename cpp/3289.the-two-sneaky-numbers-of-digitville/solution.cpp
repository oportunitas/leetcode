// Created by oportunitas at 2026/09/05 14:40
// leetgo: 1.4.18
// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 26MB/63th%)
		this looks like a brainteaser, and im sensing that there's a O(1) solution.
		
		if i have an array of size n, the intended array should be:
			[0, 1, 2, 3, 4, ..., n - 1]
		and therefore the total of all numbers in the array should be:
			(n - 1) * (n - 2) / 2
		now, an input array in this problem is always 2 bigger than its needed.

		as such, the total should have been:
			(n - 3) * (n - 4) / 2
		but there's 2 more numbers that add over to this ideal sum.

		now, the problem is, can we determine what each number is from the total,
		hmm, lets check the testcases and sums:
			1 -> 1 (intended size = 2)
			2 -> 5 (intended size = 4)
			3 -> 9 (intended size = 10); hmm, this can be either 4,5 / 3, 6 / 2, 7, etc
		so there's no O(1) approach here i suppose as long as i can think of,
		since we cant determine each number separately from the total difference alone.
		
		an O(N) solution exists, we just create an array to represent a hash function
		to store the number of occurences of a number in the array.
	*/
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> count(nums.size() - 2, 0);
		auto result {[] () {vector<int> _; _.reserve(2); return _;} ()};
		for (auto num : nums) {
			if (count[num] > 0) result.push_back(num);
			count[num] += 1;
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.getSneakyNumbers(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
