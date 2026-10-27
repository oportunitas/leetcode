// Created by oportunitas at 2026/10/27 09:46
// leetgo: 1.4.18
// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 24.8MB/99th%)
        010 not possible, a+a+1 = 2a+1 (odd number fundamental property)
            011 001 | 010
            101 100 | 101
            111 011 | 100
        pattern: remove the 1 next to the first 0 (011->001 | 010->100, 111->011)
            how? add 1 first:
                101->110
            then we reverse mask with origin original number
                110 & 010 -> 010
            this outputs the location of the first 0. shift once right
                010 -> 001
            this is the location of the last 1 before the first 0. we can reverse mask/
            subtract the original number with this
                101 & 110 / 101 - 001 -> 100
    */
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (const auto& num : nums) {
            if (num == 2) {
                ans.push_back(-1);
            } else {
                ans.push_back(num & ~(((num + 1) & ~num) >> 1));
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minBitwiseArray(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
