// Created by oportunitas at 2026/11/03 15:30
// leetgo: 1.4.18
// https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const int fast_io = [] { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    /* idea #0 (4ms/83th% | 128.3MB/73th%)
        lets optimize. since the ordering is preserved, we can just insert in order
    */
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans (nums.size(), 0);
        size_t pi {0}, ni {1};
        for (const auto& num : nums) {
            if (num > 0) {
                ans[pi] = num;
                pi += 2;
            } else {
                ans[ni] = num;
                ni += 2;
            }
        } return ans;
    }

    // /* idea #0 (11ms/29th% | 133.1MB/30th%)
    //     lets try a slower approach first: create array for positive and negative values,
    //     then append answer array.
    // */
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int> pos; pos.reserve(nums.size());
    //     vector<int> neg; neg.reserve(nums.size());
    //     vector<int> ans; ans.reserve(nums.size());
    //     for (const auto& num : nums) {
    //         if (num > 0) {
    //             pos.push_back(num); // no need for emplace_back in c++23 already existing objects
    //         } else {
    //             neg.push_back(num);
    //         }
    //     }

    //     for (size_t i {0}; i < nums.size() / 2; ++i) {
    //         ans.push_back(pos[i]); ans.push_back(neg[i]);
    //     } return ans;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.rearrangeArray(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
