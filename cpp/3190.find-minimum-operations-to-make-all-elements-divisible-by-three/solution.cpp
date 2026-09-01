// Created by oportunitas at 2026/09/01 17:21
// leetgo: 1.4.18
// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea 0
		doing mod 3 on any number would find its remainder:
			6 mod 3 = 0 -> 0
			5 mod 3 = 2 -> 1 
			4 mod 3 = 1 -> 1
			3 mod 3 = 0 -> 0
			2 mod 3 = 2 -> 1
			1 mod 3 = 1 -> 1
		using if to turn 2 to 1 might work, but its not elegant.
		a very neat way is to be able to do mod along the other way:
			6 rod 3 = 3 -> 0
			5 rod 3 = 1 -> 1
			4 rod 3 = 2 -> 1
			3 rod 3 = 3 -> 0
			2 rod 3 = 1 -> 1
			1 rod 3 = 2 -> 1
		we can do this by just doing 3 - (original modulus result):
			6 rod 3 = 3 - 0 = 3
			5 rod 3 = 3 - 2 = 1
			4 rod 3 = 3 - 1 = 2
			3 rod 3 = 3 - 0 = 3
			2 rod 3 = 3 - 2 = 1
			1 rod 3 = 3 - 1 = 2
		we can then just find the minimum between the two, and add that to the total result
	*/
    int minimumOperations(vector<int>& nums) {
		int result = 0;
		for (auto num : nums) {
			result += min((num % 3), (3 - (num % 3)));
			// println("---");
			// println("{}", num % 3);
			// println("{}", 3 - (num % 3));
			// println("{}", min((num % 3), (((-1 * num) % 3)) * -1));
		}

		return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minimumOperations(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
