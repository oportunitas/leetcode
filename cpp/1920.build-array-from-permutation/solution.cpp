// Created by oportunitas at 2026/09/01 09:05
// leetgo: 1.4.18
// https://leetcode.com/problems/build-array-from-permutation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #2
		lets now find out how to use O(1) memory:
			swapping sounds like an obvious choice, but the fact that its seems obvious is 
			what is spooky about it.

			hmm, we can do something like this though:
				Input  : [5,0,1,2,3,4]
				Output : [4,5,0,1,2,3]
				
				lets assume that the computer uses decimal to store stuff
					[05,00,01,02,03,04], in memory:
					050001020304
				we shift everything in this array forwards by one digit:
					500010203040
					[50, 00, 10, 20, 30, 40]
				and then we put the output candidate to the ones places
					[54, 05, 10, 21, 32, 43]
				and then we just delete the tens places:
					[4, 5, 0, 1, 2, 3]
				excellent!

		in binary, what this would mean is:
			first, we shift the entire array by 10.
			the reason is that the maximum number in the test case is 1000,
			just slightly below 2^10 (1024):
				[5,0,1,2,3,4], to binary (13 places for brevity):
					
		0000000000101|0000000000000|0000000000001|0000000000010|0000000000011|0000000000100
		now we shift left by 10
		1010000000000|0000000000000|0010000000000|0100000000000|0110000000000|1000000000000
		then, we loop for each number, and append the 10-left-shifted number 
		1010000000100|0000000000101|0010000000000|0100000000001|0110000000010|1000000000011
		finally, we do and operator with 0001111111111 to only retain the last 10 bits
		0000000000100|0000000000101|0000000000000|0000000000001|0000000000010|0000000000011
		excellent!
	*/

	vector<int> buildArray(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) {
			nums[i] <<= 10;
		}

		for (int i = 0; i < nums.size(); ++i) {
			// println("---");
			// println("{:013b}", nums[i]);
			// println("{:013b}", nums[nums[i] >> 10]);
			nums[i] |= nums[nums[i] >> 10] >> 10;
			// println("{:013b}", nums[i]);
		} 

		for (int i = 0; i < nums.size(); ++i) {
			// println("---");
			// println("{:013b}", nums[i]);
			nums[i] = nums[i] & 0b1111111111;
			// println("{:013b}", nums[i]);
		}
		
		return nums;
	}

	// /*idea #1 (0ms/20.4MB)
	// 	lets streamline the code a bit to make it faster.
	// */
	// vector<int> buildArray(vector<int>& nums) {
	// 	auto result = [&nums] () {vector<int> _; _.reserve(nums.size()); return _;} ();
	// 	for (int i = 0; i < nums.size(); ++i) {
	// 		result.push_back(nums[nums[i]]);
	// 	} return result;
	// }

	// /*idea #0 (3ms/20.4MB)
	// 	we can create a new array that contains the array as described.
	// 	this would mean that we're adding extra space. lets solve the O(1) memory
	// 	issue in next ideas
	// */
    // vector<int> buildArray(vector<int>& nums) {
	// 	auto result = [&nums] () {vector<int> _; _.reserve(nums.size()); return _;} ();
	// 	for (auto [i, num] : nums | views::enumerate) {
	// 		result.push_back(nums[num]);
	// 	} return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.buildArray(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
