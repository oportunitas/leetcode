// Created by oportunitas at 2026/10/13 08:49
// leetgo: 1.4.18
// https://leetcode.com/problems/construct-uniform-parity-array-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 30.1MB/92th%)
        bruh, this should be trivial, if the array has both even and odd numbers, you can turn
        all the even numbers to odd numbers by subtracting them with any odd number.
        
        so there's no way that we cant make the array all odd or all even
    */
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums1 = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.uniformArray(nums1);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
