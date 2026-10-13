// Created by oportunitas at 2026/10/13 08:55
// leetgo: 1.4.18
// https://leetcode.com/problems/separate-the-digits-in-an-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms.100th% | 14.1MB/90th%)
        we append in reverse, then reverse
    */
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (auto& num : nums | views::reverse) {
            do {
                result.push_back(num % 10);
                num /= 10;
            } while (num > 0);
        } ranges::reverse(result);
        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.separateDigits(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
