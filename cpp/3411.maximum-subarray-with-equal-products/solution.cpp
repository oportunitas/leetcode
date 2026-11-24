// Created by oportunitas at 2026/11/24 16:46
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-subarray-with-equal-products/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 27.9MB/90th%)
        although we can use prefix product array, a sliding window
        solution is more elegant, where we multiply along and move the
        r position, and whenever the current num cant divide the running
        product, we move the l pointer until it can
    */
    int maxLength(vector<int>& nums) {
        int running = 1; int ans = 2;

        int l = 0; int r = 0;
        for (; r < ssize(nums); ++r) {
            int num = nums[r];
            while (gcd(running, num) > 1) {
                running /= nums[l++];
            } running *= num;
            ans = max(ans, r - (l - 1));
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
		auto res = obj.maxLength(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
