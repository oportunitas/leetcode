// Created by oportunitas at 2026/11/08 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/count-valid-suffix-sorts-i/
// https://leetcode.com/contest/weekly-contest-527/problems/count-valid-suffix-sorts-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        array<int, 100005> count_diff {};
        int diff_count {0};

        int last_match {0};
        while (last_match < nums.size() && nums[last_match] == target[last_match]) last_match += 1;

        int last_nonin = nums.size() - 1;
        while (last_nonin > 0 && target[last_nonin - 1] >= target[last_nonin]) last_nonin -= 1;

        int ans {0};
        for (int i = nums.size() - 1; i >= 0; --i) {
            count_diff[nums[i]] += 1;
            if (count_diff[nums[i]] == 1) {
                diff_count += 1;
            }

            count_diff[target[i]] -= 1;
            if (count_diff[target[i]] == 0) {
                diff_count -= 1;
            }

            // if prefix is same, and also suffix target is nonincreasing, and also count_diff
            // is non-zero, add to ans
            if (i <= last_match && i >= last_nonin && diff_count == 0) ans += 1;
        } return ans;

        // array<int, 100005> count_diff {};
        // int diff_count {0};

        // int last_match {0};
        // while (last_match < nums.size() && nums[last_match] == target[last_match]) last_match += 1;

        // int last_nonin {nums.size() - 1};
        // while (last_nonin > 0 && target[last_nonin - 1] >= target[last_nonin]) last_nonin += 1;

        // int ans {0};
        // for (int i = nums.size() - 1; i >= 0; --i) {
        //     if (count_diff[nums[i]] == 0) diff_count += 1; //prepare for addition
        //     count_diff[nums[i]] += 1;
        //     if (count_diff[nums[i]] == 0) diff_count -= 1; //no longer any difference

        //     if (count_diff[target[i]] == 0) diff_count += 1;
        //     count_diff[target[i]] -= 1;
        //     if (count_diff[target[i]] == 0) diff_count -= 1;

        //     // if prefix is same, and also suffix target is nonincreasing, and also count_diff
        //     // is non-zero, add to ans
        //     if (i <= last_match && i >= last_nonin && diff_count == 0) ans += 1;
        // } return ans;


        // int ans {0};
        // for (int i = nums.size() - 1; i >= 0; --i) {
        //     // if (i == nums.size() - 1) {
        //     //     if (nums[i] == target[i]) {
        //     //         ans += 1;
        //     //     } continue;
        //     // }

        //     // check if target is ok (non-increasing), if not immediately return, no more
        //     if (target[i] < target[i] + 1) {
        //         return ans;
        //     }


        // }

        // // precompute counts, count_diff should tell us how many excess digits are in num vs target
        // array<int, 100005> count_diff{};
        // for (const auto& num : nums) {
        //     count_diff[num] += 1;
        // }
        // for (const auto& t : target) {
        //     count_diff[num] -= 1;
        // }

        // int total_diff {0};
        // for (const auto diff : count_diff) {
        //     total_diff += abs(diff);
        // }

        // int ans {0};
        // for (const auto& num : nums) {
        //     if (total_diff == 0) {
        //         ans += 1;
        //     }
        // }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> target = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countSuffix(nums, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
