// Created by oportunitas at 2026/10/11 12:16
// leetgo: 1.4.18
// https://leetcode.com/problems/count-digit-appearances/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 36.9MB/96th%)
        we just loop
    */
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count {0};
        for (auto& num : nums) {
            while (num > 0) {
                if (num % 10 == digit) {
                    count += 1;
                } num /= 10;
            }
        } return count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int digit = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.countDigitOccurrences(nums, digit);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
