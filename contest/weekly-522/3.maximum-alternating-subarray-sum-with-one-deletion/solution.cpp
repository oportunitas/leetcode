// Created by oportunitas at 2026/10/04 10:32
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-alternating-subarray-sum-with-one-deletion/
// https://leetcode.com/contest/weekly-contest-522/problems/maximum-alternating-subarray-sum-with-one-deletion/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
    wrong answer/uncompleted on timeout
*/
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        nums.push_back(0);
        long long y {0};
        for (const auto& [i, num] : nums | views::enumerate) {
            if (i % 2 == 0) {
                y -= num;
            } else {
                y += num;
            }
        }

        long long temp {0};
        long long max_size {LLONG_MIN};
        for (const auto& [i, num] : nums | views::enumerate) {
            long long toadd = (i % 2 == 0) ? (num) : (num * -1);
            long long now = ((2 * temp) + toadd) + y;
            max_size = max(max_size, now);

            temp += toadd;
        } 
        
        return max_size;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxAlternatingSum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
