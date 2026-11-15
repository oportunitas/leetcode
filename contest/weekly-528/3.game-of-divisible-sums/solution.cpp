// Created by oportunitas at 2026/11/15 10:10
// leetgo: 1.4.18
// https://leetcode.com/problems/game-of-divisible-sums/
// https://leetcode.com/contest/weekly-contest-528/problems/game-of-divisible-sums/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        using i64 = std::int64_t;
        auto getval = [](i64 s, i64 next) {
            return s % 3 == 0? s - next : s + next;
        };

        i64 f1 = 0; i64 f2 = 0; i64 n = ssize(nums);
        for (int i = n - 1; i >= 0; --i) {
            i64 s = nums[i];
            i64 best = getval(s, f1);
            if (i + 1 < n) {
                best = max(best, getval(s + nums[i+1], f2));
            } f2 = exchange(f1, best);
        } return f1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxDifference(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
