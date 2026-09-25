// Created by oportunitas at 2026/09/25 13:02
// leetgo: 1.4.18
// https://leetcode.com/problems/create-target-array-in-the-given-order/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 11.4MB/28th%)
        idea #0 was flawed, because it only considers numbers only moving by 1.
        lets directly insert instead, since this is a standard feature of
        std::vector
    */
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        for (const auto& [i, num] : views::zip(index, nums)) {
            result.insert(result.begin() + i, num);
        } return result;
    }

    // /* idea #0 (wrong answer)
    //     we can create a junction array to store the numbers in each index:
        
    //     [0, 1, 2, 3, 4]
    //     [0, 1, 2, 2, 1]

    //     0: [0]
    //     1: [1, 4]
    //     2: [2, 3]

    //     then we can append the reverse of each row as a result

    //     [4, 2, 4, 3, 2]
    //     [0, 0, 1, 3, 1]

    //     [4, 2]
    //     [4, 2]
    //     [3]
    // */
    // vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    //     vector<vector<int>> junctions (101, vector<int>());
    //     for (const auto& [i, num] : views::zip(index, nums)) {
    //         junctions[i].push_back(num);
    //     }

    //     vector<int> result;
    //     for (const auto& junction : junctions) {
    //         result.insert(result.end(), junction.rbegin(), junction.rend());
    //     } return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> index = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.createTargetArray(nums, index);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
